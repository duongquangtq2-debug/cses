#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    ll l = 0, r = 0;
    vector<ll> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
        l = max(l, values[i]);
        r += values[i];
    }

    auto check = [&](ll x)
    {
        ll s = 0, cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (s + values[i] > x)
            {
                s = 0;
                cnt++;
            }
            s += values[i];

            if (cnt > k)
                return false;
        }
        return true;
    };

    while (l < r)
    {
        ll mid = (r + l) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l;

    return 0;
}