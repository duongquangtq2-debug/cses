#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> values(n);
    vector<ll> sums(n + 1);
    multiset<ll> sumab;

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
        sums[i + 1] = sums[i] + values[i];
    }

    ll ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        int l = i - b;
        int r = i - a;

        if (r < 0)
            continue;

        if (l < 0)
            l = 0;

        if (l > 0)
            sumab.erase(sumab.find(sums[l - 1]));

        sumab.insert(sums[r]);
        ans = max(ans, sums[i] - *sumab.begin());
    }
    cout << ans;

    return 0;
}