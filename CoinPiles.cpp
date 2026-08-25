#include <iostream>
#include <cmath>
using namespace std;
void yesno(double a, double b)
{
    double x = (2 * b - a) / 3, y = (2 * a - b) / 3;
    if (x == floor(x) && y == floor(y) && x >= 0 && y >= 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    int n;
    double a, b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        yesno(a, b);
    }
}