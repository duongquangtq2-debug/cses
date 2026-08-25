#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> N(n - 1);
    vector<bool> TF(n + 1, true);
    TF[0] = false;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> N[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        TF[N[i]] = false;
    }

    for (int i = 0; i < n + 1; i++)
    {
        if (TF[i])
        {
            cout << i;
        }
    }
}