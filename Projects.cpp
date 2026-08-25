#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Project
{
    int s, e;
    ll r;

    bool operator<(const Project &other) const
    {
        if (e != other.e)
            return e < other.e;
        if (s != other.s)
            return s < other.s;
        return r < other.r;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Project> projects(n);

    for (auto &project : projects)
        cin >> project.s >> project.e >> project.r;

    sort(projects.begin(), projects.end());

    map<int, ll> dp;

    for (auto [start, end, reward] : projects)
    {
        ll best = reward;

        auto it = dp.lower_bound(start);
        if (it != dp.begin())
        {
            --it;
            best += it->second;
        }

        auto pre = dp.lower_bound(end);
        if (pre != dp.begin())
        {
            --pre;
            best = max(best, pre->second);
        }

        dp[end] = best;
    }

    cout << dp.rbegin()->second;
    return 0;
}