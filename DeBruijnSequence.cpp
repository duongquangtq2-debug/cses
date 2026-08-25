#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 14;
int n;
bool vis[N][2];
vector<int> ans;

void dfs(int u)
{
    for (int i = 0; i < 2; i++)
    {
        if (!vis[u][i])
        {
            vis[u][i] = true;
            int new_u = ((u << 1) | i) & ((1 << (n - 1)) - 1);
            dfs(new_u);
        }
    }
    ans.push_back(u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    if (n == 1)
    {
        cout << "01\n";
        return 0;
    }
    dfs(0);
    int start_u = ans.back();
    for (int i = n - 2; i >= 0; i--)
    {
        cout << ((start_u >> i) & 1);
    }

    for (int i = (int)ans.size() - 2; i >= 0; i--)
    {
        cout << (ans[i] & 1);
    }
    cout << "\n";
    return 0;
}