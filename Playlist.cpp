#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> id(n);
    for (auto &x : id)
    {
        cin >> x;
    }

    auto a = id;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for (int i = 0; i < n; i++)
    {
        id[i] = lower_bound(a.begin(), a.end(), id[i]) - a.begin();
    }

    vector<bool> tfid(a.size(), true);
    a.clear();
    a.shrink_to_fit();

    int ans = 0, maxans = -1;
    int l = 0, r = 0;
    while (l < n && r < n)
    {
        if (tfid[id[r]])
        {
            tfid[id[r]] = false;
            ans++;
            r++;
        }
        else
        {
            while (!tfid[id[r]])
            {
                tfid[id[l]] = true;
                ans--;
                l++;
            }
        }
        maxans = max(ans, maxans);
    }
    cout << maxans;
}