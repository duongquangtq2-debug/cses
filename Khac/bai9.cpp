#include <iostream>
using namespace std;

int main()
{
    int a = 6, b = 2;
    cout << "a+3= " << (a += 3) << endl;
    cout << "a-5= " << (a -= 5) << endl;
    cout << "a*2= " << (a *= 2) << endl;
    cout << "a%5= " << (a %= 5) << endl;
    cout << "a-(b+7)= " << (a -= (b + 7)) << endl;
}