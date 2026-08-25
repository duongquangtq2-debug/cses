#include <iostream>
using namespace std;
#define _USE_MATH_DEFINES
#include <cmath>

int main()
{
    cout << "PI = " << M_PI << endl;

    double R;
    cout << "Nhap ban kinh R = ";
    cin >> R;
    cout << "Chu vi hinh tron la: " << 2 * M_PI * R << endl;
    cout << "Dien tich hinh tron la: " << M_PI * R * R << endl;
}
