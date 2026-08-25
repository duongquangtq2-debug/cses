#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> values(n);
    for (auto &p : values)
    {
        cin >> p;
    }

    vector<int> dayso = values;
    sort(dayso.begin(), dayso.end());
    int l = 0, r = n - 1;
    int x1, x2;
    while (l < r)
    {
        if (dayso[l] + dayso[r] > x)
        {
            r--;
        }
        else if (dayso[l] + dayso[r] < x)
        {
            l++;
        }
        else
        {
            x1 = dayso[l];
            x2 = dayso[r];
            break;
        }
    }

    bool tf1 = true, tf2 = true;
    if (l == r)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (values[i - 1] == x1 && tf1)
            {
                cout << i << " ";
                tf1 = false;
            }
            else if (values[i - 1] == x2 && tf2)
            {
                cout << i << " ";
                tf2 = false;
            }
        }
    }
}