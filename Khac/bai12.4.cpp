#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    int n, i = 2;
    bool songuyento = true;
    cout << "Moi nhap vao so tu nhien n(n>=2): ";
    cin >> n;

    while (i <= sqrt(n))
    {
        if (n % i == 0)
        {
            songuyento = false;
            i++;
            break;
        }
        else
        {
            i++;
        }
    }

    if (songuyento)
    {
        cout << n << " la khong phai so nguyen to";
    }
    else
    {
        cout << n << " la so nguyen to";
    }
}