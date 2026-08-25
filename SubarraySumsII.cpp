#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
        cin >> values[i];

    map<ll, int> sums;
    ll sum = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        sums[sum]++;
        sum += values[i];
        ll k = sum - x;
        auto it = sums.find(k);
        if (it != sums.end())
            ans += it->second;
    }

    cout << ans;

    return 0;
}