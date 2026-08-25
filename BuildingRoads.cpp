#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int n, m;
vector<vector<int>> adj(maxn);
vector<bool> vis(maxn, true);
void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void dfs(int i)
{
    vis[i] = false;
    for (auto j : adj[i])
        if (vis[j])
            dfs(j);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    nhap();
    vector<int> start;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            start.push_back(i);
            dfs(i);
        }
    }
    cout << start.size() - 1 << endl;
    for (int i = 0; i < start.size() - 1; i++)
    {
        cout << start[i] << " " << start[i + 1] << endl;
    }
    return 0;
}