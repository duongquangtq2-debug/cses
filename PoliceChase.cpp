#include <bits/stdc++.h>
using namespace std;
int const maxn = 501;
long long board[maxn][maxn];
vector<int> adj[maxn];

bool bfs(int s, int t, vector<int> &parent)
{
    bool vis[maxn] = {};
    queue<int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (vis[v] || board[u][v] == 0)
                continue;
            parent[v] = u;
            if (v == t)
                return true;
            q.push(v);
            vis[v] = true;
        }
    }
    return false;
}

long long ans(int s, int t)
{
    long long max_flow = 0;
    vector<int> parent(maxn);
    while (bfs(s, t, parent))
    {
        int cur = t;
        while (cur != s)
        {
            int p = parent[cur];
            board[p][cur] = 0;
            board[cur][p] = 1;
            cur = p;
        }
        max_flow += 1;
    }
    return max_flow;
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
        board[a][b] = 1;
        board[b][a] = 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << ans(1, n);
    
    return 0;
}