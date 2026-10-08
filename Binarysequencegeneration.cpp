#include <bits/stdc++.h>
using namespace std;
int n;

void nhiphan(int x)
{
    string ans = "";
    for (int i = n - 1; i >= 0; i--)
    {
        if (x & (1 << i))
            ans += '1';
        else
            ans += '0';
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        nhiphan(i);
    }

    return 0;
}