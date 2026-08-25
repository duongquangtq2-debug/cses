#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int dp[1 << 20][20];
vector<int> adj[20];

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
        adj[a - 1].push_back(b - 1);
    }
    dp[1][0] = 1;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int u = 0; u < n; u++)
        {
            if (dp[i][u] == 0)
                continue;
            if (u == n - 1 && i != (1 << n) - 1)
                continue;
            for (auto v : adj[u])
            {
                if (i & (1 << v))
                    continue;
                int new_i = i | (1 << v);
                dp[new_i][v] = (dp[new_i][v] + dp[i][u]) % M;
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1];
    return 0;
}