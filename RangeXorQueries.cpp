#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pre[i] = pre[i - 1] ^ x;
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << (pre[b] ^ pre[a - 1]) << "\n";
    }

    return 0;
}