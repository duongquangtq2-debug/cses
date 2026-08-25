#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> before(m + 1), after(m + 1);
    for (int a = 0; a < n; a++)
    {
        int x;
        cin >> x;

        if (a == 0)
        {
            if (x == 0)
                fill(before.begin() + 1, before.end(), 1);
            else
                before[x] = 1;
            continue;
        }

        if (x == 0)
        {
            for (int i = 1; i <= m; i++)
                for (int j = i - 1; j <= i + 1; j++)
                    if (j > 0 && j <= m)
                        after[i] = (after[i] + before[j]) % M;
        }
        else
        {
            for (int j = x - 1; j <= x + 1; j++)
                if (j > 0 && j <= m)
                    after[x] = (after[x] + before[j]) % M;
        }

        swap(before, after);
        fill(after.begin(), after.end(), 0);
    }

    int ans = 0;
    for (auto it : before)
        ans = (ans + it) % M;

    cout << ans;

    return 0;
}