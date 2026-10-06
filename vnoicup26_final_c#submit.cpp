#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int ac = 0; ac < t; ac++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(m + 1);
        vector<int> ans(m + 1);
        for (int i = 1; i <= m; i++)
        {
            cin >> a[i];
        }

        vector<int> LOW, HIGHT;
        for (int i = 1; i <= n; i++)
        {
            LOW.push_back(i);
        }

        for (int u = 1; u <= m; u++)
        {
            if (LOW.size() > 1)
            {
                int stt = LOW.size() - 1;
                if (LOW[stt] == a[u])
                    stt--;
                ans[u] = LOW[stt];
                HIGHT.push_back(LOW[stt]);
                LOW.erase(LOW.begin() + stt);
            }
            else if (LOW.size())
            {
                ans[u] = LOW[0];
                if (LOW[0] == a[u])
                {
                    swap(LOW, HIGHT);
                }
                else
                {
                    HIGHT.push_back(LOW[0]);
                    LOW.erase(LOW.begin());
                }
            }
        }

        cout << "YES" << endl;
        for (int u = 1; u <= m; u++)
        {
            cout << ans[u] << " ";
        }
        cout << endl;
    }

    return 0;
}