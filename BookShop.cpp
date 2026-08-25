#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    for (auto &it : price)
        cin >> it;

    vector<int> page(n);
    for (auto &it : page)
        cin >> it;

    vector<int> dp(x + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= price[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
        }
    }
    cout << dp[x];

    return 0;
}