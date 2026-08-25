#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, c;
    if (!(cin >> a >> b >> c))
    {
        return 0;
    }

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "Vo so nghiem";
            }
            else
            {
                cout << "Vo nghiem";
            }
        }
        else
        {
            double x = -c / b;
            cout << fixed << setprecision(6) << x;
        }
        return 0;
    }

    double delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        cout << "Vo nghiem";
    }
    else if (delta == 0)
    {
        double x = -b / (2 * a);
        cout << fixed << setprecision(6) << x;
    }
    else
    {
        double sqrtDelta = sqrt(delta);
        double x1 = (-b + sqrtDelta) / (2 * a);
        double x2 = (-b - sqrtDelta) / (2 * a);
        cout << fixed << setprecision(6) << x1 << " " << x2;
    }

    return 0;
}
