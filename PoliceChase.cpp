#include <bits/stdc++.h>
using namespace std;

const int maxn = 501;

long long board[maxn][maxn];
vector<int> adj[maxn];

// Lưu các cạnh gốc để cuối cùng in ra
vector<pair<int, int>> edges;

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
    long long max_flow = 0;

    vector<int> parent(maxn);

    while (bfs(s, t, parent))
    {
        int cur = t;

        while (cur != s)
        {
            int p = parent[cur];

            // Đẩy 1 đơn vị flow
            board[p][cur] -= 1;
            board[cur][p] += 1;

            cur = p;
        }

        max_flow += 1;
    }

    return max_flow;
}

// Tìm tất cả đỉnh còn đi được từ source
void bfs2(int s, vector<bool> &vis)
{
    queue<int> q;

    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (vis[v] || board[u][v] == 0)
                continue;

            vis[v] = true;
            q.push(v);
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

        // Lưu cạnh gốc
        edges.push_back({a, b});

        // Đồ thị vô hướng
        board[a][b] = 1;
        board[b][a] = 1;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Max Flow = Min Cut
    long long flow = ans(1, n);

    // Tìm những đỉnh còn reachable từ 1
    vector<bool> from1(n + 1, false);

    bfs2(1, from1);

    // Những cạnh nối:
    // một đầu reachable
    // một đầu không reachable
    // chính là minimum cut

    vector<pair<int, int>> answer;

    for (auto [u, v] : edges)
    {
        if (from1[u] != from1[v])
        {
            answer.push_back({u, v});
        }
    }

    cout << answer.size() << '\n';

    for (auto [u, v] : answer)
    {
        cout << u << ' ' << v << '\n';
    }

    return 0;
}