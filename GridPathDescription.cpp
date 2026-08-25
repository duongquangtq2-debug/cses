#include <iostream>
#include <vector>
using namespace std;

// D, U, L, R
int nx[] = {1, -1, 0, 0};
int ny[] = {0, 0, -1, 1};
int dem = 0;

bool checkvitri(int x, int y, int buoc, const vector<vector<bool>> &visited)
{
    int a = x + nx[buoc], b = y + ny[buoc];
    if (a >= 0 && a <= 6 && b >= 0 && b <= 6)
    {
        if (visited[a][b])
        {
            return true;
        }
    }

    return false;
}

void dpf1(int x, int y, vector<vector<bool>> &mang1)
{
    mang1[x][y] = false;
    for (int i = 0; i < 4; i++)
    {
        if (checkvitri(x, y, i, mang1))
        {
            dpf1(x + nx[i], y + ny[i], mang1);
        }
    }
}

bool dpf(int x, int y, int buoc, const vector<vector<bool>> &visited)
{
    auto mang1 = visited;
    int a = x + nx[buoc], b = y + ny[buoc];
    mang1[a][b] = false;

    bool first = true;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (mang1[i][j] && first)
            {
                dpf1(i, j, mang1);
                first = false;
                break;
            }
        }
    }

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            if (mang1[i][j])
                return false;

    return true;
}

void demth(int x, int y, int n, vector<vector<bool>> &visited, const vector<int> &path)
{
    if (n == 48)
    {
        if (x == 6 && y == 0)
            dem++;
        return;
    }

    if (n < 48 && x == 6 && y == 0)
    {
        return;
    }

    if (path[n] == -1)
    {
        for (int i = 0; i < 4; i++)
        {
            if (checkvitri(x, y, i, visited) && dpf(x, y, i, visited))
            {
                visited[x + nx[i]][y + ny[i]] = false;
                demth(x + nx[i], y + ny[i], n + 1, visited, path);
                visited[x + nx[i]][y + ny[i]] = true;
            }
        }
    }
    else
    {
        if (checkvitri(x, y, path[n], visited) && dpf(x, y, path[n], visited))
        {
            visited[x + nx[path[n]]][y + ny[path[n]]] = false;
            demth(x + nx[path[n]], y + ny[path[n]], n + 1, visited, path);
            visited[x + nx[path[n]]][y + ny[path[n]]] = true;
        }
        else
        {
            return;
        }
    }
}

int main()
{

    string s;
    cin >> s;
    vector<vector<bool>> visited(7, vector<bool>(7, true));
    visited[0][0] = false;

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

    demth(0, 0, 0, visited, path);

    cout << dem << '\n';
}