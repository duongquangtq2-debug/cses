#include <iostream>
using namespace std;

int main()
{

    // toan tu logic
    int i = 10;
    cout << (i > 5 && i < 15) << endl;
    cout << (i > 10 || i < 1) << endl;
    // phep phu dinh
    cout << !(i > 10) << endl;

    int a = 6, b = 10, c = 145, d = 100;
    a++; // a = a + 1;a+=1
    b--;
    ++c;
    --d;

    cout << "a,b,c,d= " << a << "," << b << "," << c << "," << d << endl;

    // test bieu thuc phuc hop
    int x = 5, y = 10, z = x++ - ++y + 1;
    cout << "x= " << x << endl;
    cout << "y= " << y << endl;
    cout << "z= " << z << endl;
}