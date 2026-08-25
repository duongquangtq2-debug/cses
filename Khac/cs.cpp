#include <iostream>
#include <vector>
using namespace std;
bool found = false;

vector<char> checkvitri(const vector<string> &bang, const vector<string> &a, int x, int y)
{
    vector<char> res;
    for (char c = 'A'; c <= 'D'; c++)
    {
        if (c != a[x][y] && (x == 0 || c != bang[x - 1][y]) && (y == 0 || c != bang[x][y - 1]))
        {
            res.push_back(c);
        }
    }
    return res;
}

void xuatbang(const vector<string> &bang)
{
    for (auto &row : bang)
    {
        cout << row << '\n';
    }
}

void taobang(vector<string> &bang, const vector<string> &a, int x, int y)
{
    if (found)
        return;

    int n = a.size();
    int m = a[0].size();

    if (y == m)
    {
        if (x == n - 1)
        {
            xuatbang(bang);
            found = true;
            return;
        }
        else
        {

            taobang(bang, a, x + 1, 0);
            return;
        }
    }
    else
    {
        auto res = checkvitri(bang, a, x, y);
        for (int i = 0; i < res.size(); i++)
        {
            bang[x][y] = res[i];
            taobang(bang, a, x, y + 1);
            bang[x][y] = a[x][y];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> bang(n);

    for (auto &row : bang)
    {
        cin >> row;
    }
    const vector<string> a = bang;
    taobang(bang, a, 0, 0);

    if (!found)
        cout << "IMPOSSIBLE\n";
}