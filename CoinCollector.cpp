#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int nums = 0; // stt scc
long long coin_max = 0;
int coin[N];            // tien trong phong x
int scc[N];             // x thuoc scc so thu
bool vis[N];            // tham chua dfs 1
long long coin_scc[N];  // tong tien trong scc x
vector<int> new_adj[N]; // duong di thep scc
vector<int> order;
vector<int> adj[N], rev_adj[N];

void dfs1(int u)
{
    vis[u] = true;
    for (auto v : adj[u])
        if (!vis[v])
            dfs1(v);

    order.push_back(u);
}

void dfs2(int u)
{
    scc[u] = nums;
    for (auto v : rev_adj[u])
        if (scc[v] == 0)
            dfs2(v);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> coin[i];

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i);

    for (int i = n - 1; i >= 0; i--)
    {
        int v = order[i];
        if (scc[v] == 0)
        {
            nums++;
            dfs2(v);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        coin_scc[scc[i]] += coin[i];
        for (auto v : adj[i])
        {
            if (scc[v] != scc[i])
            {
                new_adj[scc[i]].push_back(scc[v]);
            }
        }
    }
    vector<long long> dp(nums + 1);
    for (int u = 1; u <= nums; u++)
    {
        dp[u] = coin_scc[u];
        coin_max = max(coin_max, dp[u]);
    }

    for (int u = 1; u <= nums; u++)
    {
        for (auto v : new_adj[u])
        {
            dp[v] = max(dp[v], dp[u] + coin_scc[v]);
            coin_max = max(coin_max, dp[v]);
        }
    }
    cout << coin_max;
    return 0;
}