#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n;
vector<pair<int, int>> mountain;
vector<int> r, l;
vector<int> tree;

int query(int node, int tl, int tr, int l, int r)
{
    if (tr < l || r < tl)
        return -INF;

    if (l <= tl && tr <= r)
        return tree[node];

    int mid = (tl + tr) / 2;

    return max(
        query(node * 2, tl, mid, l, r),
        query(node * 2 + 1, mid + 1, tr, l, r));
}

void update(int node, int tl, int tr, int pos, int val)
{
    if (tl == tr)
    {
        tree[node] = val;
        return;
    }

    int mid = (tl + tr) / 2;

    if (pos <= mid)
        update(node * 2, tl, mid, pos, val);
    else
        update(node * 2 + 1, mid + 1, tr, pos, val);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void monoStack(vector<int> &res, int lo, int hi, int step, int def)
{
    vector<pair<int, int>> stack;
    for (int i = lo; i != hi; i += step)
    {
        auto [x, y] = mountain[i];

        while (!stack.empty() && stack.back().first < x)
            stack.pop_back();

        res[y] = stack.empty() ? def : stack.back().second;
        stack.emplace_back(x, y);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    mountain.resize(n);
    r.assign(n + 2, 0);
    l.assign(n + 2, 0);
    tree.assign(4 * n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mountain[i] = {x, i + 1};
    }

    monoStack(l, 0, n, 1, 0);           // trái -> phải, mặc định 0
    monoStack(r, n - 1, -1, -1, n + 1); // phải -> trái, mặc định n + 1

    sort(mountain.begin(), mountain.end());
    for (auto [a, b] : mountain)
    {
        if (l[b] + 1 == r[b] - 1)
        {
            update(1, 1, n, b, 1);
            continue;
        }

        int x = -INF;
        if (l[b] + 1 != b)
            x = max(x, query(1, 1, n, l[b] + 1, b - 1));
        if (r[b] - 1 != b)
            x = max(x, query(1, 1, n, b + 1, r[b] - 1));
        update(1, 1, n, b, x + 1);
    }
    cout << tree[1];
    return 0;
}