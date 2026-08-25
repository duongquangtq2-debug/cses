#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int demth(const vector<int> &vitriso, const vector<int> &sothu, int x, int y)
{
    int ans = 1;
    int a = sothu[x], b = sothu[y];
    if (a < b)
        swap(a, b);

    if (a - b == 1)
    {
        for (int i = b - 1; i < a + 1; i++)
        {
            if (vitriso[i] > vitriso[i + 1])
                ans++;
        }
    }
    else
    {
        for (int i = a - 1; i < a + 1; i++)
        {
            if (vitriso[i] > vitriso[i + 1])
                ans++;
        }

        for (int i = b - 1; i < b + 1; i++)
        {
            if (vitriso[i] > vitriso[i + 1])
                ans++;
        }
    }

    return ans;
}

int main()
{
    int n, m, ans = 1;
    cin >> n >> m;
    vector<int> sothu(n + 1);
    vector<int> vitriso(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sothu[i] = x;
        vitriso[x] = i;
    }

    for (int i = 1; i < n; i++)
    {
        if (vitriso[i] > vitriso[i + 1])
            ans++;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int a1 = demth(vitriso, sothu, a, b);
        swap(vitriso[sothu[a]], vitriso[sothu[b]]);
        swap(sothu[a], sothu[b]);
        a1 = demth(vitriso, sothu, a, b) - a1;
        ans = ans + a1;
        cout << ans << endl;
    }
}
