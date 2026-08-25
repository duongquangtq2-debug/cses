#include <iostream>
using namespace std;

int main()
{
    int tuoi;
    cout << "Nhap tuoi tu 0 den 120: ";
    cin >> tuoi;

    while (tuoi < 0 || tuoi > 120)
    {
        cout << "Nhap lai tuoi tu 0 den 120: ";
        cin >> tuoi;
    }
    cout << "ok";
}