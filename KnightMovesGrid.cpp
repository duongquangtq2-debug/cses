#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    vector<vector<int>> banco(n, vector<int>(n, -1));
    banco[0][0] = 0;

    vector<vector<pair<int, int>>> v(n + 2);
    v[0].push_back({0, 0});

    for (int i = 1; i < n + 2; i++)
    {
        for (int j = 0; j < (int)v[i - 1].size(); j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int nx = v[i - 1][j].first + dx[k];
                int ny = v[i - 1][j].second + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && banco[nx][ny] == -1)
                {
                    banco[nx][ny] = i;
                    v[i].push_back({nx, ny});
                }
            }
        }
    }

    for (int i = 0; i < banco.size(); i++)
    {
        for (int j = 0; j < banco[i].size(); j++)
        {
            cout << banco[i][j] << " ";
        }
        cout << endl;
    }
}