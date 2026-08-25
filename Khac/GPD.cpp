#include <iostream>
using namespace std;

string s;
bool vis[7][7];
int ans = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int step)
{
    // Đến đích
    if (x == 6 && y == 0)
    {
        if (step == 48)
            ans++;
        return;
    }

    // Chưa đủ bước mà đã tới đích
    if (step == 48)
        return;

    vis[x][y] = true;

    // Cắt tỉa 1
    if ((x == 0 || vis[x - 1][y]) &&
        (x == 6 || vis[x + 1][y]) &&
        y > 0 && !vis[x][y - 1] &&
        y < 6 && !vis[x][y + 1])
    {
        vis[x][y] = false;
        return;
    }

    // Cắt tỉa 2
    if ((y == 0 || vis[x][y - 1]) &&
        (y == 6 || vis[x][y + 1]) &&
        x > 0 && !vis[x - 1][y] &&
        x < 6 && !vis[x + 1][y])
    {
        vis[x][y] = false;
        return;
    }

    // D
    if (s[step] == '?' || s[step] == 'D')
    {
        int nx = x + 1, ny = y;
        if (nx < 7 && !vis[nx][ny])
            dfs(nx, ny, step + 1);
    }

    // U
    if (s[step] == '?' || s[step] == 'U')
    {
        int nx = x - 1, ny = y;
        if (nx >= 0 && !vis[nx][ny])
            dfs(nx, ny, step + 1);
    }

    // L
    if (s[step] == '?' || s[step] == 'L')
    {
        int nx = x, ny = y - 1;
        if (ny >= 0 && !vis[nx][ny])
            dfs(nx, ny, step + 1);
    }

    // R
    if (s[step] == '?' || s[step] == 'R')
    {
        int nx = x, ny = y + 1;
        if (ny < 7 && !vis[nx][ny])
            dfs(nx, ny, step + 1);
    }

    vis[x][y] = false;
}

int main()
{
    cin >> s;
    dfs(0, 0, 0);
    cout << ans << '\n';
}