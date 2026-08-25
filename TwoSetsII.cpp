#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;
    if (sum & 1)
    {
        cout << 0;
        return 0;
    }

    vector<int> dp(sum / 2 + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = sum / 2; j >= i; j--)
            dp[j] = (dp[j] + dp[j - i]) % M;

    long long inv2 = (M + 1) / 2; // nghịch đảo modulo của 2
    long long ans = (long long)dp[sum / 2] * inv2 % M;
    cout << ans;

    return 0;
}