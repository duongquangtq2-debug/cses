#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    int n, songuoc = 0;
    cout << "Moi nhap vao so tu nhien n: ";
    cin >> n;
    while (n > 0)
    {
        songuoc = songuoc * 10 + (n % 10);
        n = floor(n / 10);
    }
    cout << "so nguoc cua n la: " << songuoc;
}