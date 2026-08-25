#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int n, m;

void build(int row, int mask, int new_mask, vector<int> &th)
{
    if (row == n - 1)
    {
        if (mask & (1 << row))
            th.push_back(new_mask);
        else
            th.push_back(new_mask | (1 << row));
        return;
    }
    if (!(mask & (1 << row)))
    {
        if (mask & (1 << (row + 1)))
        {
            build(row + 1,
                  mask | (1 << row),
                  new_mask | (1 << row),
                  th);
        }
        else
        {
            build(row + 1, mask | (1 << row) | (1 << (row + 1)), new_mask, th);
            build(row + 1, mask | 1 << row, new_mask | 1 << row, th);
        }
    }
    else
    {
        build(row + 1, mask, new_mask, th);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    map<int, long long> dp;
    dp[0] = 1;
    vector<int> mask;
    mask.push_back(0);
    for (int i = 0; i < m; i++)
    {
        map<int, long long> ndp;
        for (auto [mask, ways] : dp)
        {
            vector<int> nhap;
            int new_mask = 0;
            build(0, mask, new_mask, nhap);
            for (auto b : nhap)
            {
                ndp[b] += ways;
                ndp[b] %= M;
            }
        }
        swap(dp, ndp);
    }
    cout << dp[0];

    return 0;
}