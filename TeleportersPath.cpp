#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m;
int to[N], from[N];
vector<int> adj[N];
vector<int> cycle;

void dfs(int u)
{
    while (!adj[u].empty())
    {
        int v = adj[u].back();
        adj[u].pop_back();
        dfs(v);
    }
    cycle.push_back(u);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        to[b]++;
        from[a]++;
    }

    if (from[1] != to[1] + 1 || from[n] + 1 != to[n])
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 2; i < n; i++)
    {
        if (from[i] != to[i])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    dfs(1);
    if (cycle.size() != m + 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int i = cycle.size() - 1; i >= 0; i--)
    {
        cout << cycle[i] << "\n";
    }
}