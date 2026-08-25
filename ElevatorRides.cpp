#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    vector<pair<int, int>> dp(1 << n, {n + 1, 0});
    dp[0] = {1, 0};
    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(i & (1 << j)))
            {
                int newMask = i | (1 << j);
                pair<int, int> ans = dp[i];
                ans.second = ans.second + weights[j];
                if (ans.second > x)
                {
                    ans.first++;
                    ans.second = weights[j];
                }
                dp[newMask] = min(dp[newMask], ans);
            }
        }
    }
    cout << dp[(1 << n) - 1].first;

    return 0;
}