#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using minpq = priority_queue<
    pair<ll, int>,
    vector<pair<ll, int>>,
    greater<pair<ll, int>>>;
const ll INF = 1e18;
void minweight(int x, vector<ll> &dist, const vector<vector<pair<int, ll>>> &direct)
{
    minpq qp;
    dist[x] = 0;
    qp.push({0, x});
    while (!qp.empty())
    {
        auto [a, b] = qp.top();
        qp.pop();
        if (a != dist[b])
            continue;
        for (auto [v, w] : direct[b])
        {
            if (a + w < dist[v])
            {
                dist[v] = a + w;
                qp.push({dist[v], v});
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

    vector<vector<pair<int, ll>>> direct(n + 1);
    vector<vector<pair<int, ll>>> res_direct(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        direct[a].push_back({b, c});
        res_direct[b].push_back({a, c});
    }

    vector<ll> dist(n + 1, INF);
    vector<ll> res_dist(n + 1, INF);
    minweight(1, dist, direct);
    minweight(n, res_dist, res_direct);

    ll ans = INF;
    for (int u = 1; u <= n; u++)
    {
        for (auto [v, w] : direct[u])
        {
            if (dist[u] == INF || res_dist[v] == INF)
                continue;
            ans = min(ans, dist[u] + w / 2 + res_dist[v]);
        }
    }
    cout << ans;

    return 0;
}