#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> digit;
long long memo[20][11][2][2];
bool vis[20][11][2][2];

ll dp(int pos, int last_digit, bool tight, bool started)
{
    if (pos == (int)digit.size())
        return 1;
    if (vis[pos][last_digit][tight][started])
        return memo[pos][last_digit][tight][started];
    int limit;
    if (tight)
        limit = digit[pos];
    else
        limit = 9;

    ll ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        if (i != last_digit || !started)
            ans += dp(pos + 1, i, tight & (i == digit[pos]), started | (i != 0));
    }
    vis[pos][last_digit][tight][started] = true;
    return memo[pos][last_digit][tight][started] = ans;
}
ll solve(ll x)
{
    if (x < 0)
        return 0;

    digit.clear();

    if (x == 0)
        digit.push_back(0);
    else
    {
        while (x > 0)
        {
            digit.push_back(x % 10);
            x /= 10;
        }
        reverse(digit.begin(), digit.end());
    }

    memset(vis, 0, sizeof(vis));

    return dp(0, 0, true, false);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1);

    return 0;
}