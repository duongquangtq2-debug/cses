#include <iostream>
using namespace std;
int main()
{
    int nhietdo = 27;
    cout << "nhiet do phong " << nhietdo << endl;
    int *controt;
    controt = &nhietdo;
    cout << "dia chi " << controt << endl;
    *controt = 200;
    cout << "nhiet do phong " << nhietdo << endl;
}