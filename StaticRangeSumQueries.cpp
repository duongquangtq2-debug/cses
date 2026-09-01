#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << "\n";
    }

    return 0;
}