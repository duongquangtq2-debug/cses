#include <iostream>
#include <vector>
using namespace std;

void print(int n)
{
    if (n == 0)
        cout << "1 2" << endl;
    else if (n == 1)
        cout << "1 3" << endl;
    else if (n == 2)
        cout << "2 1" << endl;
    else if (n == 3)
        cout << "2 3" << endl;
    else if (n == 4)
        cout << "3 1" << endl;
    else if (n == 5)
        cout << "3 2" << endl;
}

void u(int a, int x)
{
    if (a == 1)
    {
        print(x);
    }
    else
    {
        if (x == 0)
        {
            u(a - 1, 1);
            print(x);
            u(a - 1, 5);
        }
        else if (x == 1)
        {
            u(a - 1, 0);
            print(x);
            u(a - 1, 3);
        }
        else if (x == 2)
        {
            u(a - 1, 3);
            print(x);
            u(a - 1, 4);
        }
        else if (x == 3)
        {
            u(a - 1, 2);
            print(x);
            u(a - 1, 1);
        }
        else if (x == 4)
        {
            u(a - 1, 5);
            print(x);
            u(a - 1, 2);
        }
        else if (x == 5)
        {
            u(a - 1, 4);
            print(x);
            u(a - 1, 0);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    u(n, 1);
}