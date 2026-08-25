#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == b)
        return a;
    if (a < b)
        swap(a, b);

    int r = 0;
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    cout << gcd(10, 14);
}