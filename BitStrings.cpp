#include <iostream>
using namespace std;

int main()
{
    int n;
    const long long mod = 1000000007;
    long long sodu = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sodu = ((2 * sodu) % mod);
    }
    cout << sodu;
}