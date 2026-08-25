#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5;
int n, m;
vector<vector<int>> adj(N + 1);
vector<int> dp(N + 1);
vector<bool> vis(N + 1);

int f(int x)
{
    if (vis[x])
        return dp[x];
    vis[x] = true;
    dp[x] = 0;
    if (x == n)
        return dp[n] = 1;
    for (auto y : adj[x])
    {
        f(y);
        dp[x] += dp[y];
        dp[x] %= M;
    }
    return dp[x];
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
        adj[a].push_back(b);
    }
    f(1);
    cout << dp[1];
    return 0;
}