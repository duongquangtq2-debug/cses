#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, so0 = 0;
    cin >> n;

    int x = log(n) / log(5);
    for (int i = 1; i <= x; i++)
    {
        so0 += (n / pow(5, i));
    }
    cout << so0;
}