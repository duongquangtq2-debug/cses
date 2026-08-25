#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sum = 0;
    cin >> n;

    vector<ll> remainder(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum = ((sum + x) % n + n) % n;
        remainder[sum]++;
    }

    ll ans = 0;
    ans += (remainder[0] + remainder[0] * (remainder[0] - 1) / 2);
    for (int i = 1; i < n; i++)
    {
        if (remainder[i] > 1)
        {
            ans += remainder[i] * (remainder[i] - 1) / 2;
        }
    }

    cout << ans;

    return 0;
}