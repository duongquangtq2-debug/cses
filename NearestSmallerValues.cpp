#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> values;
vector<int> nearest;

void check(int r, int x)
{
    if (r == 0 && values[0] >= values[x])
        nearest[x] = 0;

    else if (values[r] < values[x])
        nearest[x] = r + 1;
    else
        check(nearest[r] - 1, x);
}

int main()
{
    cin >> n;

    values.resize(n);
    nearest.resize(n);

    for (auto &it : values)
        cin >> it;

    for (int i = 1; i < n; i++)
        check(i - 1, i);

    for (auto it : nearest)
        cout << it << " ";
}