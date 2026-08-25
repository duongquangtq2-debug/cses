#include <iostream>
#include <vector>
using namespace std;

long long vitri(long long x, long long y)
{
    if (x == y)
    {
        return 1 + x * (x - 1);
    }
    else if (x > y)
    {
        if (x % 2 == 0)
        {
            return vitri(x, x) + (x - y);
        }
        else
        {
            return vitri(x, x) - (x - y);
        }
    }
    else
    {
        if (y % 2 == 0)
        {
            return vitri(y, y) - (y - x);
        }
        else
        {
            return vitri(y, y) + (y - x);
        }
    }
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> XY(2 * n);
    for (long long i = 0; i < 2 * n; i++)
    {
        cin >> XY[i];
    }

    for (long long i = 0; i < 2 * n; i += 2)
    {
        cout << vitri(XY[i], XY[i + 1]) << endl;
    }
}