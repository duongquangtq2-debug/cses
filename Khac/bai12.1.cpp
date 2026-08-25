#include <iostream>
using namespace std;

int main()
{
    int n, tongn=0, i = 1;
    cout << "Nhap n: ";
    cin >> n;

    while (i <= n)
    {
        tongn += i;
        i++;
    }
    cout << "Tong cua " << n << " so tn dau la: " << tongn;
}
