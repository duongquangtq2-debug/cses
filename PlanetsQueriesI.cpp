#include <bits/stdc++.h>
using namespace std;
int dp[200001][30];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> dp[i][0];

    for (int i = 1; i < 30; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        int x = a;
        for (int i = 0; i < 30; i++)
        {
            if (b & (1 << i))
            {
                x = dp[x][i];
            }
        }
        cout << x << endl;
    }

    return 0;
}