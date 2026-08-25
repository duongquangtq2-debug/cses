#include <iostream>
using namespace std;

int main()
{
    long long dem = 0, x1, x2;
    int n;
    cin >> n;
    cin >> x1;
    for (long long i = 1; i < n; i++)
    {
        cin >> x2;
        if (x1 <= x2)
        {
            x1 = x2;
        }
        if (x1 > x2)
        {
            dem = dem + x1 - x2;
        }
    }
    cout << dem;
}