#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> array1(n), array2(m);
    for (auto &it : array1)
        cin >> it;
    for (auto &it : array2)
        cin >> it;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (array1[i - 1] == array2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    vector<int> lcs;
    for (int i = n, j = m; i && j;)
    {
        if (array1[i - 1] == array2[j - 1])
        {
            lcs.push_back(array1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(lcs.begin(), lcs.end());

    cout << dp[n][m] << '\n';
    for (int x : lcs)
        cout << x << ' ';

    return 0;
}