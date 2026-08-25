#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1e18;
priority_queue<
    pair<ll, int>,
    vector<pair<ll, int>>,
    greater<pair<ll, int>>>
    pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(
        n + 1,
        vector<ll>(n + 1, INF));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (ll)c);
        dist[b][a] = min(dist[b][a], (ll)c);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                dist[i][j] = 0;

    for (int t = 1; t <= n; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j],
                                 dist[i][t] + dist[t][j]);
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        ll t = dist[x][y];
        if (t == INF)
            t = -1;
        cout << t << endl;
    }
    return 0;
}