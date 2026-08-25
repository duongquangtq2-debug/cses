#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector<vector<pair<int, ll>>> adj;
vector<ll> lengths;
priority_queue<
    pair<ll, int>,
    vector<pair<ll, int>>,
    greater<pair<ll, int>>>
    pq;

void nhap()
{
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int t, e, w;
        cin >> t >> e >> w;
        adj[t].push_back({e, w});
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    nhap();
    lengths.resize(n + 1, 1e18 + 1);
    lengths[1] = 0;
    pq.push({lengths[1], 1});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != lengths[u])
            continue;
        for (auto [e, w] : adj[u])
        {
            if (lengths[e] > d + w)
            {
                lengths[e] = d + w;
                pq.push({lengths[e], e});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << lengths[i] << " ";
    }
    return 0;
}