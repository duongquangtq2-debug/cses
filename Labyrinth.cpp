#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int ni[] = {1, -1, 0, 0};
int nj[] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    pair<int, int> end;
    queue<pair<int, int>> dist;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> parent(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            if (x == 'A')
            {
                map[i][j] = 0;
                dist.push({i, j});
            }
            else if (x == 'B')
            {
                map[i][j] = INF;
                end = {i, j};
            }
            else if (x == '.')
                map[i][j] = -1;
            else
                map[i][j] = -2;
        }
    }
    bool path = false;
    while (!path && !dist.empty())
    {
        auto [i, j] = dist.front();
        dist.pop();
        for (int a = 0; a < 4; a++)
        {
            int new_i = i + ni[a];
            int new_j = j + nj[a];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m)
            {
                if (map[new_i][new_j] == -1)
                {
                    map[new_i][new_j] = map[i][j] + 1;
                    parent[new_i][new_j] = a;
                    dist.push({new_i, new_j});
                }
                else if (map[new_i][new_j] == INF)
                {
                    map[new_i][new_j] = map[i][j] + 1;
                    parent[new_i][new_j] = a;
                    path = true;
                }
            }
        }
    }

    if (path)
    {
        cout << "YES" << endl;
        cout << map[end.first][end.second] << endl;
        string ans = "";
        while (true)
        {
            auto [i, j] = end;
            if (map[i][j] == 0)
                break;
            int a = parent[i][j];
            switch (a)
            {
            case 0:
                ans += 'D';
                break;
            case 1:
                ans += 'U';
                break;
            case 2:
                ans += 'R';
                break;
            default:
                ans += 'L';
                break;
            }
            end = {i - ni[a], j - nj[a]};
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    else
        cout << "NO";

    return 0;
}