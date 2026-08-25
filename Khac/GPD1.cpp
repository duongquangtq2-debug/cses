#include <iostream>
#include <vector>
using namespace std;

int nx[] = {1, -1, 0, 0};
int ny[] = {0, 0, -1, 1};
// D, U, L, R
int dem = 0;

bool checkvitri(int x, int y, int buoc, const vector<vector<bool>> &visited)
{
    int a = x + nx[buoc], b = y + ny[buoc];
    if (a >= 0 && a <= 6 && b >= 0 && b <= 6)
    {
        if (!visited[a][b])
        {
            return true;
        }
    }

    return false;
}

bool splitGrid(int x, int y, int dir, const vector<vector<bool>> &visited)
{
    bool D = true, U = true, L = true, R = true;
    int a = x + nx[dir], b = y + ny[dir];
    if (a == 6 || !visited[a + 1][b])
        D = false;
    if (a == 0 || !visited[a - 1][b])
        U = false;
    if (b == 0 || !visited[a][b - 1])
        L = false;
    if (b == 6 || !visited[a][b + 1])
        R = false;

    switch (dir)
    {
    case 0:
        U = false;
        break;
    case 1:
        D = false;
        break;
    case 2:
        R = false;
        break;
    case 3:
        L = false;
        break;
    }

    if (D && U && !L && !R)
    {
        return false;
    }
    if (!D && !U && L && R)
    {
        return false;
    }

    return true;
}

bool Manhattan(int x, int y, int step)
{
    int remain = 48 - step;
    int dist = abs(x - 6) + abs(y);

    if (dist <= remain)
        return true;

    return false;
}

void backtrack(int x, int y, int step, const vector<int> &path, vector<vector<bool>> &visited)
{
    if (step == 48 && x == 6 && y == 0)
    {
        dem++;
        return;
    }

    if (x == 6 && y == 0)
        return;

    if (path[step] == -1)
        for (int i = 0; i < 4; i++)
        {
            if (!checkvitri(x, y, i, visited))
                continue;
            if (!splitGrid(x, y, i, visited))
                continue;
            if (!Manhattan(x + nx[i], y + ny[i], step))
                continue;

            visited[x + nx[i]][y + ny[i]] = true;
            backtrack(x + nx[i], y + ny[i], step + 1, path, visited);
            visited[x + nx[i]][y + ny[i]] = false;
        }
    else
    {
        if (!checkvitri(x, y, path[step], visited))
            return;
        if (!splitGrid(x, y, path[step], visited))
            return;
        if (!Manhattan(x + nx[path[step]], y + ny[path[step]], step))
            return;

        visited[x + nx[path[step]]][y + ny[path[step]]] = true;
        backtrack(x + nx[path[step]], y + ny[path[step]], step + 1, path, visited);
        visited[x + nx[path[step]]][y + ny[path[step]]] = false;
    }
}

int main()
{
    string s;
    cin >> s;
    vector<vector<bool>> visited(7, vector<bool>(7, false));
    visited[0][0] = true;

    vector<int> path(48);

    for (int i = 0; i < 48; i++)
    {
        if (s[i] == 'D')
            path[i] = 0;
        else if (s[i] == 'U')
            path[i] = 1;
        else if (s[i] == 'L')
            path[i] = 2;
        else if (s[i] == 'R')
            path[i] = 3;
        else
            path[i] = -1; // '?'
    }

    backtrack(0, 0, 0, path, visited);
    cout << dem;
}