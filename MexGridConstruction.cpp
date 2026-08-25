#include <iostream>
#include <vector>
using namespace std;

int dienvitri(const vector<vector<int>> &mex, int x, int y)
{
    vector<bool> xuathien(200, true);
    for (int i = 0; i < x; i++)
    {
        xuathien[mex[i][y]] = false;
    }
    for (int i = 0; i < y; i++)
    {
        xuathien[mex[x][i]] = false;
    }

    for (int i = 0; i < 200; i++)
    {
        if (xuathien[i])
        {
            return i;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mex(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        mex[0][i] = i;
        mex[i][0] = i;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            mex[i][j] = dienvitri(mex, i, j);
            mex[j][i] = mex[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mex[i][j] << " ";
        }
        cout << endl;
    }
}