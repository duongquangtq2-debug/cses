#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ans = 0;
    int n, k, distinct = 0, l = 0;
    cin >> n >> k;

    vector<int> values(n);
    map<int, int> a;

    for (int r = 0; r < n; r++)
    {
        cin >> values[r];

        if (a[values[r]] == 0)
            distinct++;
        a[values[r]]++;

        while (distinct > k && l < n)
        {
            a[values[l]]--;
            if (a[values[l]] == 0)
                distinct--;

            l++;
        }

        ans += r - l + 1;
    }

    cout << ans;

    return 0;
}