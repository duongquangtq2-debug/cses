#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a,b,c,denta,x1,x2;

    cout << " tinh nghiem pt bac 2 ax^2 + bx + c = 0" <<endl;
    cout << " nhap he so a,b,c: ";
    cin >> a >> b >> c;

    denta = b*b - 4*a*c;

    if (denta > 0)
    {
        x1 = (-b + sqrt(denta)) / (2*a);
        x2 = (-b - sqrt(denta)) / (2*a);
        cout << " pt co 2 nghiem phan biet: " << endl;
        cout << " x1 = " << x1 << endl;
        cout << " x2 = " << x2 << endl;
    }
    else if (denta == 0)
    {
        x1 = -b / (2*a);
        cout << " pt co nghiem kep: " << endl;
        cout << " x = " << x1 << endl;
    }
    else
    {
        cout << " pt vo nghiem" << endl;
    }

}
