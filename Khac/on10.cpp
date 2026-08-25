#include <iostream>
using namespace std;

int main()
{
    int sotruoc = 1, sohientai = 1, sosau, n, sothun;
    cout << "Moi nhap vao n: ";
    cin >> n;
    if (n == 1 || n == 2)
    {
        sothun = 1;
    }
    else
    {
        for (int i = 3; i <= n; i++)
        {
            sosau = sotruoc + sohientai;
            sotruoc = sohientai;
            sohientai = sosau;
        }
        sothun = sosau;
    }
    cout << sothun;
}
