#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> values(n);

    for (int i = 0; i < n; i++)
    {
        int xi;
        cin >> xi;
        values[i] = {xi, i + 1};
    }

    sort(values.begin(), values.end());

    for (int i = 0; i < n - 3; i++)
    {
        int j = n - 1;
        while (values[j].first + values[i + 2].first + values[i + 1].first + values[i].first > x)
        {
            j--;
        }
        for (; j > i + 2; j--)
        {
            int l = i + 1, r = j - 1;
            while (l < r)
            {
                int sum = values[i].first + values[l].first + values[r].first + values[j].first;
                if (sum < x)
                    l++;
                else if (sum > x)
                    r--;
                else
                {
                    cout << values[i].second << " " << values[l].second << " " << values[r].second << " " << values[j].second;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}