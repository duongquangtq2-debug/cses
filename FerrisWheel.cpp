#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    vector<int> weight(n);
    for (int &i : weight)
    {
        cin >> i;
    }

    sort(weight.begin(), weight.end());
    int l = 0, r = n - 1, ans = 0;
    while (l < n && r >= 0 && l <= r)
    {
        if (l == r)
        {
            ans++;
            break;
        }

        if (weight[l] + weight[r] > s)
        {
            r--;
            ans++;
        }
        else
        {
            r--;
            l++;
            ans++;
        }
    }
    cout << ans;
}