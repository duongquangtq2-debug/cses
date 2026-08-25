#include <iostream>
using namespace std;

int main()
{
    int nam;
    cout << "Nhap nam: ";
    cin >> nam;

    if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
    {
        cout << " day la nam nhuan";
    }
    else
    {
        cout << "day khong phai nam nhuan";
    }
}