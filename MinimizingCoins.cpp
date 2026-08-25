#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    vector<int> numbers(1e6 + 1, -1);

    for (auto &it : coins)
    {
        cin >> it;
        numbers[it] = 1;
    }

    for (int i = 1; i <= x; i++)
    {
        int ans = 1e9;
        if (numbers[i] != -1)
            continue;
        for (auto it : coins)
        {
            if (i - it > 0 && numbers[i - it] > 0)
                ans = min(ans, numbers[i - it] + 1);
        }

        if (ans != 1e9)
            numbers[i] = ans;
    }

    cout << numbers[x];

    return 0;
}