#include <bits/stdc++.h>
using namespace std;
pair<int, int> knightMoves[] = {
    {-2, -1},
    {-2, 1},
    {-1, -2},
    {-1, 2},
    {1, -2},
    {1, 2},
    {2, -1},
    {2, 1}};
int chess[8][8];
int dp[8][8];

int check(int x, int y)
{
    int ans = 0;
    for (auto [rx, ry] : knightMoves)
    {
        if (x + rx >= 0 && x + rx <= 7 && y + ry >= 0 && y + ry <= 7)
        {
            ans++;
        }
    }
    return ans;
}
void create()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chess[i][j] = check(i, j);
        }
    }
}

void bt(int x, int y)
{
    if (dp[x][y] == 64)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << dp[j][i] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    vector<tuple<int, int, int>> order;
    for (auto [rx, ry] : knightMoves)
    {
        int new_x = x + rx;
        int new_y = y + ry;

        if (new_x < 0 || new_x >= 8 || new_y < 0 || new_y >= 8)
            continue;

        if (dp[new_x][new_y] != 0)
            continue;

        order.push_back({chess[new_x][new_y], new_x, new_y});
    }
    sort(order.begin(), order.end());
    for (auto [w, u, v] : order)
    {
        dp[u][v] = dp[x][y] + 1;
        bt(u, v);
        dp[u][v] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    create();
    dp[x - 1][y - 1] = 1;
    bt(x - 1, y - 1);

    return 0;
}