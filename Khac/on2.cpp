#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, i = 0, tong = 0;
    cout << "Nhap vao so tu nhien n: ";
    cin >> n;
    while (i <= n)
    {
        tong += pow(i, 2);
        i++;
    }
    cout << "Tong binh phuong la: " << tong;
}