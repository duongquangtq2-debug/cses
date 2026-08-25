#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long tongdayso = 0;
    cin >> n;
    vector<int> dayso(n);
    vector<long long> tong(1 << n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> dayso[i];
        tongdayso += dayso[i];
    }
    long long tongmax = 0, s = tongdayso / 2;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                tong[i] += dayso[j];
            }
        }
        if (tong[i] > tongmax && tong[i] <= s)
        {
            tongmax = tong[i];
        }
    }
    cout << tongdayso - 2 * tongmax;
}