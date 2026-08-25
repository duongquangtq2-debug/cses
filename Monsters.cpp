#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;
bool found = false;

pair<int, int> parent[1002][1002];
char direction[1002][1002];

tuple<int, int, char> moves[] = {
    {0, 1, 'R'},
    {0, -1, 'L'},
    {1, 0, 'D'},
    {-1, 0, 'U'}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<vector<int>> monsterTime(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, INF));

    queue<pair<int, int>> monsterQ;
    queue<pair<int, int>> playerQ;

    pair<int, int> start, finish;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            switch (c)
            {
            case '#':
                monsterTime[i][j] = -1;
                break;

            case 'M':
                monsterQ.push({i, j});
                monsterTime[i][j] = 0;
                break;

            case 'A':
                playerQ.push({i, j});
                start = {i, j};
                monsterTime[i][j] = INF;
                break;

            default:
                monsterTime[i][j] = INF;
            }
        }
    }

    while (!monsterQ.empty())
    {
        auto [x, y] = monsterQ.front();
        monsterQ.pop();

        for (auto [dx, dy, dir] : moves)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (monsterTime[nx][ny] == -1)
                continue;

            if (monsterTime[nx][ny] == INF)
            {
                monsterTime[nx][ny] = monsterTime[x][y] + 1;
                monsterQ.push({nx, ny});
            }
        }
    }

    dist[start.first][start.second] = 0;
    while (!playerQ.empty())
    {
        auto [x, y] = playerQ.front();
        playerQ.pop();

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        {
            finish = {x, y};
            found = true;
            break;
        }

        for (auto [dx, dy, dir] : moves)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (monsterTime[nx][ny] == -1)
                continue;

            if (dist[nx][ny] != INF)
                continue;

            if (dist[x][y] + 1 < monsterTime[nx][ny])
            {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                direction[nx][ny] = dir;
                playerQ.push({nx, ny});
            }
        }
    }

    if (!found)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    string path;
    pair<int, int> cur = finish;

    while (cur != start)
    {
        auto [x, y] = cur;
        path += direction[x][y];
        cur = parent[x][y];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    cout << path;
}