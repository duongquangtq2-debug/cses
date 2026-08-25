#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "Nhap n (n le): ";
    cin >> n;

    int a[100][100] = {0};

    int x = n / 2;
    int y = n / 2;
    int num = 1;

    a[x][y] = num++;

    int step = 1;

    while (num <= n * n)
    {
        // Sang phải
        for (int i = 0; i < step && num <= n * n; i++)
        {
            y++;
            a[x][y] = num++;
        }

        // Lên
        for (int i = 0; i < step && num <= n * n; i++)
        {
            x--;
            a[x][y] = num++;
        }

        step++;

        // Sang trái
        for (int i = 0; i < step && num <= n * n; i++)
        {
            y--;
            a[x][y] = num++;
        }

        // Xuống
        for (int i = 0; i < step && num <= n * n; i++)
        {
            x++;
            a[x][y] = num++;
        }

        step++;
    }

    // In ma trận
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }

    return 0;
}