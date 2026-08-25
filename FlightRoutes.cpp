#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;

        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    vector<int> cnt(n + 1);
    priority_queue<pair<ll, int>,
                   vector<pair<ll, int>>,
                   greater<pair<ll, int>>>
        pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        cnt[u]++;

        if (cnt[u] > k)
            continue;

        if (u == n)
            cout << d << ' ';

        for (auto [v, w] : adj[u])
        {
            pq.push({d + w, v});
        }
    }
    return 0;
}