#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge
{
    int u;
    int v;
    ll w;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edga;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edga.push_back({a, b, c});
    }

    vector<ll> dist(n + 1);
    vector<int> parent(n + 1);
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        ans = -1;
        for (auto [v, u, w] : edga)
        {
            if (dist[v] + w < dist[u])
            {
                dist[u] = dist[v] + w;
                parent[u] = v;
                ans = u;
            }
        }
    }

    if (ans != -1)
    {
        cout << "YES" << endl;

        for (int i = 0; i < n; i++)
            ans = parent[ans];
        vector<int> cycle;
        int cur = ans;
        do
        {
            cycle.push_back(cur);
            cur = parent[cur];
        } while (cur != ans);
        cycle.push_back(ans);
        reverse(cycle.begin(), cycle.end());

        for (auto x : cycle)
            cout << x << " ";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}