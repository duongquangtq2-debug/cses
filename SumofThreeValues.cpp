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

    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum = values[i].first + values[l].first + values[r].first;
            if (sum < x)
                l++;
            else if (sum > x)
                r--;
            else
            {
                cout << values[i].second << " " << values[l].second << " " << values[r].second;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}