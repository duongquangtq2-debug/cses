#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
vector<int> adj[N], rev_adj[N];
vector<bool> visited(N);
vector<int> order;
int kingdom[N];
int nums = 0;

void dfs1(int u)
{
    visited[u] = true;
    for (auto v : adj[u])
        if (!visited[v])
            dfs1(v);
    order.push_back(u);
}

void dfs2(int u)
{
    kingdom[u] = nums;
    for (auto v : rev_adj[u])
        if (kingdom[v] == 0)
            dfs2(v);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs1(i);

    reverse(order.begin(), order.end());

    for (int u : order)
    {
        if (kingdom[u] == 0)
        {
            nums++;
            dfs2(u);
        }
    }

    cout << nums << '\n';

    for (int i = 1; i <= n; i++)
        cout << kingdom[i] << ' ';

    return 0;
}