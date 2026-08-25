#include <bits/stdc++.h>
using namespace std;

int dp(int n)
{
    if (n < 10)
        return 1;

    int maxn = 0;
    for (int x = n; x > 0; x /= 10)
    {
        int i = x % 10;
        maxn = max(maxn, i);
    }

    int n1 = dp(n - maxn);
    return n1 + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int x = dp(n);
    cout << x;

    return 0;
}