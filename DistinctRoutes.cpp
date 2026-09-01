#include <bits/stdc++.h>
using namespace std;

const int N = 501;

int n, m;
int board[N][N];
int flow[N][N];

vector<int> adj[N];

bool bfs(int s, int t, vector<int> &parent)
{
    vector<bool> vis(N);
    queue<int> q;

    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (vis[v] || board[u][v] == 0)
                continue;

            parent[v] = u;
            vis[v] = true;

            if (v == t)
                return true;

            q.push(v);
        }
    }

    return false;
}

long long ans(int s, int t)
{
    long long max_flows = 0;
    vector<int> parent(N);

    while (bfs(s, t, parent))
    {
        int v = t;

        while (v != s)
        {
            int u = parent[v];

            board[u][v] -= 1;
            board[v][u] += 1;

            flow[u][v] += 1;
            flow[v][u] -= 1;

            v = u;
        }

        max_flows++;
    }

    return max_flows;
}

void find_path(int u, int t, vector<int> &path)
{
    path.push_back(u);

    if (u == t)
        return;

    for (int v : adj[u])
    {
        if (flow[u][v] > 0)
        {
            flow[u][v]--;
            find_path(v, t, path);
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        board[a][b] = 1;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long x = ans(1, n);

    cout << x << "\n";

    for (int i = 0; i < x; i++)
    {
        vector<int> path;

        find_path(1, n, path);

        cout << path.size() << "\n";

        for (int u : path)
            cout << u << " ";

        cout << "\n";
    }

    return 0;
}