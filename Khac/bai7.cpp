#include <iostream>
using namespace std;

int main()
{
    //khoi tao bien
    int i1 = 2;
    int i2 = 5;
    int i3 = -3;
    double d1 = 2.0;
    double d2 = 5.0;
    double d3 = -0.5;
    
    cout << "i1 + (i2*i3) = " << i1 + (i2 * i3) << endl;

    cout << "i1 * (i2 + i3) = " << i1 * (i2 + i3) << endl;

    cout << "i1 / (i2 + i3) = " << i1 / (i2 + i3) << endl;

    double kq1 = (double)i1/i2 + i3;
    cout << "i1/i2 + i3 = " << kq1 << endl;

    double kq2 = 3 + 4 + (double)5 / 3;
    cout << "3+4+5/3 = " << kq2 << endl;

    double kq3 = (double)(3 + 4 + 5 )/ 3;
    cout << "(3+4+5)/3 = " << kq3 << endl;

    cout<< "d1c+c(d2*d3) = " << d1 + (d2 * d3) << endl;

    cout<< "d1 + d2*d3 = " << d1 + d2 * d3 << endl;

    cout << "d1/d2 + d3 = " << d1 / d2 + d3 << endl;

    cout << "d1/(d2-d3) = " << d1 / (d2 - d3) << endl;

    cout << "d1 +d2 + d3/3 = " << d1 + d2 + d3 / 3 << endl;

    cout << "(d1 + d2 + d3)/3 = " << (d1 + d2 + d3) / 3 << endl;

    cout << "3*(d1 + d2)*(d1-d3) = " << 3 * (d1 + d2) * (d1 - d3) << endl;




    
}