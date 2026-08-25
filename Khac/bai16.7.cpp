#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Moi nhap so nguyen duong n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Khong hop le";
    }
    else
    {
        for (int k = 1; k <= n; k++)
        {
            int tong = 0;
            for (int i = 1; i < k; i++)
            {
                if (k % i == 0)
                {
                    tong += i;
                }
            }

            if (tong == k)
            {
                cout << k << " ";
            }
        }
    }

    return 0;
}