#include <iostream>
using namespace std;

int main()
{
    /*int a = 1, tong = 0;
    do
    {
        tong += a;
        a++;
    } while (a <= 5);
    cout << "tong= " << tong;
    */

    // while true
    int n = 0;
    while (true)
    {
        cout << "n= " << n << endl;
        n++;
        if (n == 100)
            break;
    }
}