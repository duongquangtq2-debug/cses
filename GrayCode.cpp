#include <iostream>
#include <vector>
using namespace std;

void inbit(int n, const int a, vector<bool> &bit)
{

    if (n == 1)
    {

        if (bit[0])
        {
            bit[0] = false;
        }
        else
        {
            bit[0] = true;
        }

        for (int i = 0; i < a; i++)
        {
            cout << bit[i];
        }
        cout << endl;
    }
    else
    {
        inbit(n - 1, a, bit);

        if (bit[n - 1])
        {
            bit[n - 1] = false;
        }
        else
        {
            bit[n - 1] = true;
        }

        for (int i = 0; i < a; i++)
        {
            cout << bit[i];
        }
        cout << endl;

        inbit(n - 1, a, bit);
    }
}

int main()
{
    int n;
    cin >> n;
    const int a = n;
    vector<bool> bit(n, false);

    for (int i = 0; i < a; i++)
    {
        cout << bit[i];
    }
    cout << endl;

    inbit(n, a, bit);
}