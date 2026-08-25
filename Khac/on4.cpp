#include <iostream>
using namespace std;

int main()
{
    int x = 1;
    while (x <= 9)
    {
        int y = 1;
        while (y <= 9)
        {
            cout << x << "*" << y << "=" << x * y << endl;
            y++;
        }
        cout << endl;
        x++;
    }
}
