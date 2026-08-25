#include <iostream>
using namespace std;

void chiadoi(int x)
{
    if (x % 4 == 1 || x % 4 == 2)
        cout << "NO";
    else if (x % 4 == 0)
    {
        cout << "YES" << endl;
        int n = x / 4;
        cout << 2 * n << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        for (int i = (3 * n + 1); i <= 4 * n; i++)
        {
            cout << i << " ";
        }
        cout << endl;

        cout << 2 * n << endl;
        for (int i = n + 1; i <= 3 * n; i++)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "YES" << endl;
        int n = (x - 3) / 4;
        cout << 2 * n + 2 << endl;
        for (int i = 1; i <= n + 1; i++)
        {
            cout << i << " ";
        }
        cout << 2 * n + 2 << " ";
        for (int i = (3 * n + 4); i <= 4 * n + 3; i++)
        {
            cout << i << " ";
        }
        cout << endl;

        cout << 2 * n + 1 << endl;
        for (int i = n + 2; i <= 2 * n + 1; i++)
        {
            cout << i << " ";
        }
        for (int i = 2 * n + 3; i <= 3 * n + 3; i++)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    chiadoi(n);
}