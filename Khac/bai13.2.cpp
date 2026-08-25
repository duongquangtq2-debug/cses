#include <iostream>
using namespace std;

int main()
{
    int n, giaithua = 1;
    cout << "Moi nhap so tu nhien n: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        giaithua = giaithua * i;
    }
    cout << "ket qua " << n << "! = " << giaithua;
}