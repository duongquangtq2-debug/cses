#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
long long diff[N];
long long a[N];

void update(int k, int u)
{
    for (; k <= n; k += k & (-k))
    {
        diff[k] += u;
    }
}

long long query(int k)
{
    long long sum = 0;
    for (; k > 0; k -= k & (-k))
    {
        sum += diff[k];
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
        cin >> a[i];
        update(i, a[i] - a[i - 1]);
    }

    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            update(a, u);
            update(b + 1, -u);
        }
        else
        {
            int x;
            cin >> x;
            cout << query(x) << "\n";
        }
    }

    return 0;
}