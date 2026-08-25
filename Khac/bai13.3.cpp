#include <iostream>
using namespace std;

int main()
{
    int n, tong = 0;
    cout << "Moi nhap so tu nhien n: ";
    cin >> n;

    if (n % 2 == 0)
    {
        for (int i = 2; i <= n; i += 2)
        {
            tong += i;
        }
        cout << "Tong cua cac so chan tu 0 toi n la: " << tong;
    }
    else
    {
        cout << "toi luoi tinh";
    }
}