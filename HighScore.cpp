#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = -(1LL << 60);

struct Edge
{
    int u, v;
    ll w;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edge(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        --edge[i].u;
        --edge[i].v;
    }

    vector<vector<int>> rev(n);
    vector<bool> can(n, false);
    for (auto [u, v, w] : edge)
        rev[v].push_back(u);
    queue<int> q;
    q.push(n - 1);
    can[n - 1] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : rev[v])
        {
            if (!can[u])
            {
                can[u] = true;
                q.push(u);
            }
        }
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto [u, v, w] : edge)
        {
            if (dist[u] == INF)
                continue;
            dist[v] = max(dist[v], dist[u] + w);
        }
    }

    bool ans = false;
    for (auto [u, v, w] : edge)
    {
        if (dist[u] == INF)
            continue;

        if (dist[u] + w > dist[v])
        {
            if (can[v])
            {
                ans = true;
                break;
            }

            dist[v] = dist[u] + w;
        }
    }

    if (ans)
        cout << -1;
    else
        cout << dist[n - 1];
    return 0;
}