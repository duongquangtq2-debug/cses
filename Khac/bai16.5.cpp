#include <iostream>
using namespace std;

int main()
{
    int a, b, a1, k;
    cout << "Moi nhap khoang [a,b]: ";
    cin >> a >> b;

    if (b - a < 3)
    {
        cout << "loai";
    }
    else
    {
        if (a % 3 == 0)
            k = 0;
        else if (a % 3 == 1)
            k = 2;
        else
            k = 1;

        a1 = a + k;

        cout << "Nhung so chia het cho 3 tu " << a << " den " << b << " la: ";

        for (int i = a1; i <= b; i += 3)
        {
            cout << i << " ";
        }
    }

    return 0;
}