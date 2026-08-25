#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005;
vector<int> bit(N);
void update(int x, int i)
{
    while (x < N)
    {
        bit[x] += i;
        x += x & (-x);
    }
}

int query(int x)
{
    int sum = 0;
    while (x)
    {
        sum += bit[x];
        x -= x & (-x);
    }
    return sum;
}
struct Range
{
    int l, r, id;

    bool operator<(const Range &other) const
    {
        if (l != other.l)
            return l < other.l;
        return r > other.r;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<Range> a(n);
    vector<vector<bool>> tf(2, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }

    {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = a[i].r;

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for (auto &x : a)
        {
            x.r = lower_bound(v.begin(), v.end(), x.r) - v.begin() + 1;
            update(x.r, 1);
        }
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        int x = query(a[i].r) - 1;
        if (x > 0)
            tf[0][a[i].id] = true;
        update(a[i].r, -1);
    }

    for (auto &x : a)
    {
        update(x.r, 1);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int x = i - query(a[i].r - 1);
        if (x > 0)
            tf[1][a[i].id] = true;
        update(a[i].r, -1);
    }

    for (auto &row : tf)
    {
        for (bool x : row)
            cout << x << " ";
        cout << '\n';
    }
}