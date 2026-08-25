#include <iostream>
#include <cmath>
using namespace std;

void thuasont(int n)
{
    bool dautien = true;
    for (int a = 2; a <= n; a += 1)
    {
        int dem = 0;

        while (n % a == 0)
        {
            dem++;
            n /= a;
        }
        if (dem > 0)
        {

            if (dem > 0)
            {
                if (!dautien)
                    cout << ".";

                cout << a;

                if (dem > 1)
                    cout << "^" << dem;

                dautien = false;
            }
        }
    }

    if (n > 1)
    {
        if (!dautien)
            cout << ".";

        cout << n;
    }
}

int main()
{
    thuasont(9);
}