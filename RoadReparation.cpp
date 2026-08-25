#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 1;
int n, m;
int parent[N], sz[N];

void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    make_set();
    vector<tuple<ll, int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());

    ll ans = 0;
    for (auto [w, u, v] : edges)
    {
        int a = find(u), b = find(v);
        if (a == b)
            continue;
        ans += w;
        unite(a, b);
    }

    if (sz[find(1)] == n)
    {
        cout << ans;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}