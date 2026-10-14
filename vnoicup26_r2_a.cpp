#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long sum = 0;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
            sum += ar[i];
        }

        if (n % 3 == 0)
        {
            cout << sum << "\n";
        }
        else if (n % 3 == 1)
        {
            int minar = 1e9 + 7;
            for (int i = 0; i < n; i += 3)
            {
                minar = min(minar, ar[i]);
            }
            cout << sum - minar << " ";
        }
        else
        {
            long long ans = 0;
            for (int i = 0; 3 * i < n; i++)
            {
                for (int j = 0; 3 * j + 3 * i < n; j++)
                {
                    ans = max(ans, sum - ar[3 * i] - ar[3 * j + 3 * i + 1]);
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}