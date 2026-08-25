#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            char c;
            cin >> c;
            if (c == '.')
                board[i][j] = 0;
            else
                board[i][j] = -1;
        }
    }
    if (board[0][0] != -1)
        board[0][0] = 1;

    auto update = [&](int i, int j)
    {
        if (board[i][j] == -1)
            return;

        if (i > 0 && board[i - 1][j] != -1)
            board[i][j] += board[i - 1][j];
        if (j > 0 && board[i][j - 1] != -1)
            board[i][j] += board[i][j - 1];
        board[i][j] %= M;
        return;
    };

    for (int sum = 1; sum <= 2 * n - 2; sum++)
    {
        for (int i = 0; i <= sum; i++)
        {
            int j = sum - i;
            if (i < n && j < n)
            {
                update(i, j);
            }
        }
    }

    int x = board[n - 1][n - 1];
    if (x == -1)
        x = 0;
    cout << x;

    return 0;
}