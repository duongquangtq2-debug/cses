#include <iostream>
#include <vector>
using namespace std;

void xuatdanhsach(vector<vector<int>> &danhsach)
{
    int n = danhsach[0].size();
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << danhsach[i][j] << " ";
        }
        cout << endl;
    }
}

void raad(int n, int x, int y)
{
    vector<vector<int>> danhsach(2, vector<int>(n));
    int thhoa = n - x - y;

    for (int i = 0; i < n; i++)
    {
        danhsach[0][i] = i + 1;
    }

    if (x == 0 && y == 0)
    {
        cout << "YES" << endl;

        for (int i = 0; i < n; i++)
        {
            danhsach[1][i] = i + 1;
        }
        xuatdanhsach(danhsach);
        return;
    }

    if (x == 0 || y == 0)
    {
        cout << "NO" << endl;
        return;
    }

    if (thhoa < 0)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = n; i > n - thhoa; i--)
        {
            danhsach[1][i - 1] = i;
            // viet tu n-thhoa den n-1 cua hang 1 con 0 den n-thhoa-1
        }

        for (int i = 0; i < x; i++)
        {
            danhsach[1][i] = n - thhoa - x + 1 + i;
            // in theo thu tu tang dan de x thang vd 1/2 2/3 3/4 4/5 ...
        }
        int dem = 1;
        for (int i = x; i < x + y; i++)
        {
            danhsach[1][i] = dem;
            dem++;
        }
        xuatdanhsach(danhsach);
        return;
    }
}
int main()
{
    int n, x, y, t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> x >> y;
        raad(n, y, x);
    }
}