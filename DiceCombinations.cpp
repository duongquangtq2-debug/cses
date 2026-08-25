#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e = 1e9 + 7;
    cin >> n;
    vector<int> values(n + 1);
    values[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = max(0, i - 6); j < i; j++)
        {
            values[i] = (values[i] + values[j]) % e;
        }
    }
    cout << values[n];
}