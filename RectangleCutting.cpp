#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1));
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            int ans = INT_MAX;
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                for (int x = 1; x <= i / 2; x++)
                {
                    ans = min(ans, dp[x][j] + dp[i - x][j] + 1);
                }
                for (int x = 1; x <= j / 2; x++)
                {
                    ans = min(ans, dp[i][x] + dp[i][j - x] + 1);
                }
                dp[i][j] = ans;
            }
        }
    }

    cout << dp[a][b];
    return 0;
}