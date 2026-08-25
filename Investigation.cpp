#include <bits/stdc++.h>
using namespace std;
using ll = long long;
priority_queue<
    pair<ll, int>,
    vector<pair<ll, int>>,
    greater<pair<ll, int>>>
    pq;
const int N = 1e5 + 1;
const int M = 1e9 + 7;
int n, m;
ll dist[N];
int ways[N], mn[N], mx[N];
vector<vector<pair<int, ll>>> adj(N + 1);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    fill(dist, dist + N, LLONG_MAX);
    dist[1] = 0;
    ways[1] = 1;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [cost, start] = pq.top();
        pq.pop();

        if (cost != dist[start])
            continue;
        for (auto [u, w] : adj[start])
        {
            ll new_dist = cost + w;
            if (new_dist < dist[u])
            {
                dist[u] = new_dist;
                pq.push({new_dist, u});
                ways[u] = ways[start];
                mn[u] = mn[start] + 1;
                mx[u] = mx[start] + 1;
            }
            else if (new_dist == dist[u])
            {
                ways[u] += ways[start];
                ways[u] %= M;
                mn[u] = min(mn[u], mn[start] + 1);
                mx[u] = max(mx[u], mx[start] + 1);
            }
        }
    }
    cout << dist[n] << " " << ways[n] << " " << mn[n] << " " << mx[n] << " ";
    return 0;
}