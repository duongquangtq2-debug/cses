#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
int a[N];
int tree[N * 4];

void update(int node, int l, int r, int k, int u)
{
    if (l == r)
    {
        tree[l] += u;
        return;
    }
    mid = l + (l - r) / 2;
    if (k <= mid)
    {
        update(node * 2, l, mid, k, u);
    }
    else
    {
        update(node * 2 + 1, mid + 1, r, k, u);
    }
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int l, int r, int u)
{
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}