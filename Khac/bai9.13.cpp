#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Nhap do dai ba canh tam giac a, b, c: ";
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a)
    {
        cout << "Day la tam giac";
        if (a == b && b == c)
        {
            cout << "Day la tam giac deu";
        }
        else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
        {
            if (a == b || b == c || c == a)
            {
                cout << "Day la tam giac vuong can";
            }
            else
            {
                cout << "Day la tam giac vuong";
            }
        }
        else if (a == b || b == c || c == a)
        {
            cout << "Day la tam giac can";
        }

        else
        {
            cout << "Day la tam giac thuong";
        }
    }
    else
    {
        cout << "Day khong phai tam giac";
    }
}