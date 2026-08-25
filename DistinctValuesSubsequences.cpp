#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, size;
    cin >> n;
    vector<int> nums(n);
    for (auto &x : nums)
    {
        cin >> x;
    }

    {
        auto a = nums;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        for (auto &x : nums)
        {
            auto it = lower_bound(a.begin(), a.end(), x);
            x = it - a.begin();
        }
        size = a.size();
    }
    vector<int> values(size, 0);
    for (auto x : nums)
    {
        values[x]++;
    }

    long long round = 1;
    const int mod = 1e9 + 7;
    for (auto x : values)
    {
        round = (round * (x + 1)) % mod;
    }
    cout << round - 1;
}