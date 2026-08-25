#include <iostream>
using namespace std;

int phuontrinh(int n)
{
    if (n == 1)
        return 2;
    return n + phuontrinh(n - 1) * 2;
}

int main()
{
    int n;
    cin >> n;
    cout << phuontrinh(n);
}