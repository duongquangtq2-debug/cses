#include <iostream>
using namespace std;

int main()
{
    // toan gan tu
    int x = 10;
    x += 5; // x=x+5
    cout << "x=" << x << endl;

    // gan tru
    int x2 = 8;
    x2 -= 5;
    cout << "x2=" << x2 << endl;

    // gan nhan
    int x3 = 4;
    x3 *= 5;
    cout << "x3=" << x3 << endl;

    // gan chia
    double x4 = 9;
    x4 /= 5;
    cout << "x4=" << x4 << endl;

    // gan chia lay du
    int x5 = 20;
    x5 %= 6;
    cout << "x5=" << x5 << endl;

    // so sanh
    int a = 5;
    int b = 6;
    cout << "a==b: " << (a == b) << endl;
    cout << "a!=b: " << (a != b) << endl;
    cout << "a>b: " << (a > b) << endl;
    cout << "a<b: " << (a < b) << endl;
    cout << "a>=b: " << (a >= b) << endl;
    cout << "a<=b: " << (a <= b) << endl;
}