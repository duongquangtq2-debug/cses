#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, ans = 0;
    cin >> n >> k;

    vector<pair<int, int>> movies(n);
    multiset<int> ends;

    for (int i = 0; i < k; i++)
        ends.insert(0);

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        movies[i] = {r, l};
    }

    sort(movies.begin(), movies.end());

    for (auto x : movies)
    {
        auto it = ends.upper_bound(x.second);
        if (it != ends.begin())
        {
            ends.erase(prev(it));
            ends.insert(x.first);
            ans++;
        }
    }
    cout << ans;

    return 0;
}