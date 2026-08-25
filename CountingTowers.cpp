#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, maxn = 0;
    cin >> t;
    vector<int> values(t);
    for (auto &it : values)
    {
        cin >> it;
        maxn = max(maxn, it);
    }

    vector<vector<long long>> towers(maxn + 1, vector<long long>(2));
    towers[1][0] = 1;
    towers[1][1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        towers[i][0] = (2 * towers[i - 1][0] + towers[i - 1][1]) % M;
        towers[i][1] = (towers[i - 1][0] + 4 * towers[i - 1][1]) % M;
    }

    for (auto x : values)
    {
        cout << (towers[x][0] + towers[x][1]) % M << endl;
    }

    return 0;
}