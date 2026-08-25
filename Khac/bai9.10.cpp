#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, delta, x1, x2;
    cout << "Nhap he so a,b,c: ";
    cin >> a >> b >> c;

    if (a == 0)
    {
        if (b != 0)
        {
            cout << "Ngiem cua pt la: " << (-c / b) << endl;
        }
        else
        {
            if (c == 0)
            {
                cout << "pt co vo so no";
            }
            else
            {
                cout << "pt vo no";
            }
        }
    }
    else
    {
        delta = pow(b, 2) - 4 * a * c;
        if (delta == 0)
        {
            cout << "PT co nghiem kep la: " << (-b / (2 * a));
        }
        else if (delta > 0)
        {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:\n";
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else
        {
            cout << "pt vo no";
        }
    }
}