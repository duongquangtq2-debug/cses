#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, m;
bool vis[N];
bool vis_id[2 * N];
int deg[N];
vector<int> circuit;
vector<pair<int, int>> adj[N];

void checkqueue(int x)
{
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (auto [v, id] : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void dfs(int u)
{
    while (!adj[u].empty())
    {
        auto [v, id] = adj[u].back();
        adj[u].pop_back();
        if (vis_id[id])
            continue;
        vis_id[id] = true;
        dfs(v);
    }
    circuit.push_back(u);
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
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        deg[a]++;
        deg[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            vis[i] = true;
        else if (deg[i] % 2 == 1)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    checkqueue(1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    dfs(1);
    for (int i = circuit.size() - 1; i >= 0; i--)
    {
        cout << circuit[i] << " ";
    }

    return 0;
}