#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

vector<int> bit(2e5 + 1);

void update(int pos, int val)
{
    while (pos <= 2e5)
    {
        bit[pos] += val;
        if (bit[pos] >= MOD)
            bit[pos] -= MOD;
        pos += pos & -pos;
    }
}

int query(int pos)
{
    int sum = 0;
    while (pos > 0)
    {
        sum += bit[pos];
        if (sum >= MOD)
            sum -= MOD;
        pos -= pos & -pos;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    for (auto &a : x)
        cin >> a;
    auto example = x;
    sort(example.begin(), example.end());
    example.erase(unique(example.begin(), example.end()), example.end());
    for (int i = 0; i < n; i++)
    {
        x[i] = lower_bound(example.begin(), example.end(), x[i]) - example.begin() + 1;
    }
    for (auto a : x)
    {
        update(a, query(a - 1) + 1);
    }
    cout << query(example.size());

    return 0;
}