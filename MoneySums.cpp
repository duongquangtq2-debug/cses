#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sum = 0;
    cin >> n;
    vector<int> coins(n);
    for (auto &x : coins)
    {
        cin >> x;
        sum += x;
    }
    vector<bool> values(sum + 1);
    values[0] = true;
    for (auto x : coins)
    {
        for (int i = sum; i >= x; i--)
        {
            if (values[i])
                continue;

            values[i] = values[i - x];
        }
    }

    int ans = 0;
    for (int i = 1; i <= sum; i++)
        if (values[i])
            ans++;
    cout << ans << endl;

    for (int i = 1; i <= sum; i++)
        if (values[i])
            cout << i << " ";

    return 0;
}