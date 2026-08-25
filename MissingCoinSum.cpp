#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    for (auto &p : values)
    {
        cin >> p;
    }
    sort(values.begin(), values.end());
    long long end;
    if (values[0] == 1)
    {
        end = 1;
    }
    else
    {
        cout << 1;
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (values[i] >= end + 2)
        {
            cout << end + 1;
            return 0;
        }
        else
        {
            end += values[i];
            if (i == n - 1)
            {
                cout << end + 1;
                return 0;
            }
        }
    }
}