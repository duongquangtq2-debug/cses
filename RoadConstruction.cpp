#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n, m;
int num, szmax = 1;
int parent[N], sz[N];

void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        szmax = max(szmax, sz[a]);
        num--;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    num = n;
    make_set();

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        unite(a, b);
        cout << num << " " << szmax << endl;
    }

    return 0;
}