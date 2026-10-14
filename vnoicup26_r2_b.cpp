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
        cin >> n;

        vector<int> color(n + 1, 1);
        vector<vector<int>> adj(n + 1);

        int k = log2(n) + 1;
        cout << k << "\n";

        for (int i = 2; i <= n; i++)
        {
            color[i]++;
            for (int j = i * 2; j <= n; j += i)
            {
                color[j] = max(color[j], color[i]);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << color[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}