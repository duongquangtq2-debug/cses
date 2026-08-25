#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, e = 1e9 + 7;
    cin >> n >> x;

    vector<int> c(n);
    vector<int> ways(x + 1);

    ways[0] = 1;
    for (auto &x : c)
        cin >> x;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
            if (i - c[j] >= 0)
                ways[i] = (ways[i] + ways[i - c[j]]) % e;
    }

    cout << ways[x];

    return 0;
}