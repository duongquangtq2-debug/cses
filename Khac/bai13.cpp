#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Moi nhap vao so n: ";
    cin >> n;
    int div = n % 2;

    switch (div)
    {
    case 0:
        cout << n << " la so chan";
        break;
    default:
        cout << n << " la so le";
        break;
    }
}