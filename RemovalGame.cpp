#include <bits/stdc++.h>
using namespace std;

void update(int l, int r, vector<vector<long long>> &dp, const vector<long long> &x)
{
    if (l == r)
    {
        dp[l][r] = x[l];
        return;
    }
    if (dp[l][r] != LLONG_MIN)
    {
        return;
    }

    update(l + 1, r, dp, x);
    update(l, r - 1, dp, x);
    dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> x(n);
    vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MIN));
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum += x[i];
    }

    update(0, n - 1, dp, x);
    cout << (sum + dp[0][n - 1]) / 2;

    return 0;
}