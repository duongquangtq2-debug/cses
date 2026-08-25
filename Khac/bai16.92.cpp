#include <iostream>
using namespace std;

int tonguoc(int n)
{
    if (n == 1)
        return 1;
    int tong = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {

            tong += i;
            if (i * i != n)
            {
                tong = tong + n / i;
            }
        }
    }
    return tong;
}

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        if (tonguoc(i) == i)
        {
            cout << i << " ";
        }
    }
}