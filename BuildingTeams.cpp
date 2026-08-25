#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int n, m;

vector<vector<int>> friendship(maxn);
vector<bool> vis(maxn, false);
vector<int> team(maxn);

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }
}

void dfs(int a)
{
    vis[a] = true;
    for (auto b : friendship[a])
    {
        if (!vis[b])
        {
            team[b] = 3 - team[a];
            dfs(b);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    nhap();

    for (int a = 1; a <= n; a++)
    {
        if (!vis[a])
        {
            team[a] = 1;
            dfs(a);
        }
    }
    for (int a = 1; a <= n; a++)
    {
        for (auto b : friendship[a])
        {
            if (team[a] == team[b])
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << team[i] << " ";
    return 0;
}