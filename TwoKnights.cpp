#include <iostream>
#include <cmath>
using namespace std;

long long socach(int n)
{
    return (pow(n, 4) - 9 * n * n + 24 * n - 16) / 2;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << socach(i) << endl;
    }
}