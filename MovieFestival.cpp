#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int sofilm(const vector<pair<int, int>> &movies, int p)
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    vector<pair<int, int>> movies;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }

    sort(movies.begin(), movies.end());

    auto it = unique(movies.begin(), movies.end(), [](const pair<int, int> &a, const pair<int, int> &b)
                     { return a.first == b.first; });

    movies.erase(it, movies.end());

    vector<int> ans(movies.size());
    vector<int> max_ans(movies.size() + 1, 0);

    for (int i = movies.size() - 1; i >= 0; i--)
    {
        auto match = lower_bound(movies.begin(), movies.end(), make_pair(movies[i].second, 0));

        if (match != movies.end())
        {
            int match_idx = match - movies.begin();
            ans[i] = max_ans[match_idx] + 1;
        }
        else
        {

            ans[i] = 1;
        }
        max_ans[i] = max(ans[i], max_ans[i + 1]);
    }

    cout << max_ans[0];
}