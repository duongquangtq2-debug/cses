#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> values(n);

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    long long cur = values[0], ans = values[0];
    for (int i = 1; i < n; i++)
    {
        cur = max((long long)values[i], (long long)(cur + values[i]));
        ans = max(ans, cur);
    }
    cout << ans;
}