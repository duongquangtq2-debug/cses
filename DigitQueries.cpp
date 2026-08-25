#include <iostream>
#include <cmath>
using namespace std;

long long pow10(int n)
{
    long long p = 1;
    for (int i = 1; i <= n; i++)
    {
        p = p * 10;
    }
    return p;
}

long long solgcs(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n * 9 * pow10(n - 1) + solgcs(n - 1);
    }
}

void cstk(long long a, int k)
{
    int len = 0;
    long long t = a;
    while (t > 0)
    {
        len++;
        t /= 10;
    }
    int shift = len - k;
    int digit = a / pow10(shift) % 10;
    cout << digit;
}
int main()
{
    long long n;
    int solan;
    cin >> solan;
    for (int i = 0; i < solan; i++)
    {
        cin >> n;
        int k = -1;
        do
        {
            k++;
        } while (solgcs(k) < n);

        // so can tim co k chu so
        n = n - solgcs(k - 1); // con lai bao nhieu chu so co k chu so

        // n=q*k+r
        long long q = n / k;
        long long r = n % k;

        if (r == 0)
        {
            cstk(pow10(k - 1) + q - 1, k);
        }
        else
        {
            cstk(pow10(k - 1) + q, r);
        }
        cout << endl;
    }
}