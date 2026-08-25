#include <bits/stdc++.h>
using namespace std;
int a[] = {1, 0, -1, 0};
int b[] = {0, 1, 0, -1};

void bfs(int i, int j, vector<vector<bool>> &room)
{
    room[i][j] = false;
    for (int x = 0; x < 4; x++)
        if (room[i + a[x]][j + b[x]])
            bfs(i + a[x], j + b[x], room);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<bool>> room(n + 2, vector<bool>(m + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            if (x == '.')
                room[i][j] = 1;
            else
                room[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (room[i][j])
            {
                ans++;
                bfs(i, j, room);
            }
        }
    }
    cout << ans;
    return 0;
}
