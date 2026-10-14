#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;
    vector<int> ar(n + 1);
    vector<ll> sum(n + 1);
    for (int u = 1; u <= n; u++)
    {
        cin >> ar[u];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            sum[i] += (ar[i] % ar[j]);
            sum[i] += (ar[j] % ar[i]);
        }
    }

    for (int i = 0; i <= n; i++)
    {
        cout << sum[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < p; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << "\n";
    }

    return 0;
}