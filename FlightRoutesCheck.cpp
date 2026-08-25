#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
vector<int> adj[N], rev_adj[N];
bool canGo[N], canBack[N];

void bfs(int src, vector<int> g[], bool mark[])
{
    queue<int> q;
    q.push(src);
    mark[src] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (!mark[v])
            {
                mark[v] = true;
                q.push(v);
            }
        }
    }
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

    bfs(1, adj, canGo);
    bfs(1, rev_adj, canBack);

    for (int i = 1; i <= n; i++)
    {
        if (!canGo[i])
        {
            cout << "NO\n"
                 << 1 << ' ' << i << '\n';
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!canBack[i])
        {
            cout << "NO\n"
                 << i << ' ' << 1 << '\n';
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}