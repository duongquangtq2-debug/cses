#include <iostream>
using namespace std;

int main()
{
    int n, tong = 0;
    cout << "Moi nhap so tu nhien n: ";
    cin >> n;

    for (int i = 1; i <= n; i += 2)
    {
        if (i == 3)
        {
            continue;
        }
        else
        {
            tong += i;
        }
    }
    cout << tong;
}