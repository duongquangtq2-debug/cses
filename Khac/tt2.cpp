#include <iostream>
using namespace std;

int f(int x)
{
    if (x == 1)
    {
        return 1;
    }
    else if (x <= 0)
    {
        return 0; // hoặc báo lỗi
    }
    else if (x % 2 == 0)
    {
        return f(x / 2) * 2 + 1;
    }
    else
    {
        return f((x - 1) / 2) * 2 - 1;
    }
}

int main()
{
    int n;
    cout << "Dien n: ";
    cin >> n;

    cout << f(n) << endl;

    return 0;
}