#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Nhap vao so nguyen n: ";
    cin >> n;
    if (n > 0)
    {
        cout << "So duong";
    }
    else if (n < 0)
    {
        cout << "So am";
    }
    else
    {
        cout << "So 0";
    }
}