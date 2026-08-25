#include <iostream>
#include <algorithm>
using namespace std;

void sapxep(int a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        bool swapped = false;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sapxep(a, n);
}