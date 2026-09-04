#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 5;
int n, q;
int values[N];
long long bit[N];

void update(int p, long long val)
{
    for (; p <= n; p += p & -p)
    {
        bit[p] += val;
    }
}

long long query(int p)
{
    long long sum = 0;
    for (; p > 0; p -= p & -p)
    {
        sum += bit[p];
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        values[i] = x;
        update(i, x);
    }

    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(b, c - values[b]);
            values[b] = c;
        }
        else
        {
            cout << query(c) - query(b - 1) << "\n";
        }
    }

    return 0;
}