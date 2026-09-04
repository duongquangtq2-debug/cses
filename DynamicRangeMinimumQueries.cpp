#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 2e5 + 1;
int a[N];
int tree[4 * N];

void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = a[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    return;
}

void update(int node, int l, int r, int k, int u)
{
    if (l == r)
    {
        tree[node] = u;
        return;
    }

    int mid = l + (r - l) / 2;
    if (k <= mid)
        update(node * 2, l, mid, k, u);
    else
        update(node * 2 + 1, mid + 1, r, k, u);

    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int l, int r, int tl, int tr)
{
    if (tr < l || r < tl)
        return INF;

    if (tl <= l && r <= tr)
        return tree[node];

    int mid = l + (r - l) / 2;
    int p1 = query(node * 2, l, mid, tl, tr);
    int p2 = query(node * 2 + 1, mid + 1, r, tl, tr);
    return min(p1, p2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 0; i < q; i++)
    {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1)
        {
            update(1, 1, n, x, y);
        }
        else
        {
            cout << query(1, 1, n, x, y) << "\n";
        }
    }

    return 0;
}
