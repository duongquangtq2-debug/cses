#include <iostream>
using namespace std;

int main()
{
    int thang;
    cout << "Moi nhap vao thang: ";
    cin >> thang;

    switch (thang)
    {
    case 1:
    case 2:
    case 3:
        cout << "Day la qui 1 ";
        break;
    case 4:
    case 5:
    case 6:
        cout << "Day la qui 2 ";
        break;
    case 7:
    case 8:
    case 9:
        cout << "Day la qui 4 ";
        break;
    case 10:
    case 11:
    case 12:
        cout << "Day la qui 4 ";
        break;
    default:
        cout << "linh ting ";
        break;
    }
}