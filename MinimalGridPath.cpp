#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &x : grid)
        cin >> x;

    vector<pair<int, int>> cur;
    cur.push_back({0, 0});
    string ans;
    ans += grid[0][0];
    while (ans.size() != 2 * n - 1)
    {

        char best = 'Z';

        for (auto [x, y] : cur)
        {
            if (x + 1 < n)
                best = min(best, grid[x + 1][y]);

            if (y + 1 < n)
                best = min(best, grid[x][y + 1]);
        }

        vector<pair<int, int>> next;
        for (auto [x, y] : cur)
        {
            if (x + 1 < n && grid[x + 1][y] == best)
                next.push_back({x + 1, y});

            if (y + 1 < n && grid[x][y + 1] == best)
                next.push_back({x, y + 1});
        }
        ans += best;
        sort(next.begin(), next.end());
        next.erase(unique(next.begin(), next.end()), next.end());
        swap(cur, next);
    }
    cout << ans;

    return 0;
}