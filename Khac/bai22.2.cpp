#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    int mang1[4][6];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            mang1[i][j] = dis(gen);
        }
    }

    // in ra mang 2 chieu
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << mang1[i][j] << " ";
        }
        cout << endl;
    }

    int mx = mang1[0][0], mn = mang1[0][0], tong = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (mang1[i][j] > mx)
            {
                mx = mang1[i][j];
            }
            if (mang1[i][j] < mn)
            {
                mn = mang1[i][j];
            }
            tong += mang1[i][j];
        }
    }

    cout << "so max: " << mx << endl;
    cout << "so min: " << mn << endl;
    cout << "tong la: " << tong << endl;
    int a, solan = 0;
    cout << "Nhap so a: ";
    cin >> a;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (a == mang1[i][j])
            {
                solan += 1;
            }
        }
    }

    if (solan == 0)
    {
        cout << "khong xuat hien"<< endl;
    }
    else
    {
        cout << "so xuat hien: " << solan << endl;
    }
}
