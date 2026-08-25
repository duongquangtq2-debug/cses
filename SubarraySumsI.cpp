#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<long long> prefix(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        prefix[i] = prefix[i - 1] + val;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (binary_search(prefix.begin(), prefix.begin() + i + 1, prefix[i] - x))
            ans++;
    }
    cout << ans;
    return 0;
}