#include <iostream>
using namespace std;

int main()
{
    float x, y, tong, hieu;
    cout << " nhap tong cua hai so x va y: ";
    cin >> tong;
    cout << " nhap hieu cua hai so x va y: ";
    cin >> hieu;

    x = (tong + hieu) / 2;
    y = (tong - hieu) / 2;
    cout << " gia tri cua x la: " << x << endl;
    cout << " gia tri cua y la: " << y << endl;
}