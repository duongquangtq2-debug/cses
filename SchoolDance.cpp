#include <bits/stdc++.h>
using namespace std;
const int N = 501;
vector<int> adj[N];
vector<int> match(N);

bool dfs(int u, vector<bool> &vis)
{
    for (auto v : adj[u])
    {
        if (vis[v])
            continue;
        vis[v] = true;
        if (match[v] == 0 || dfs(match[v], vis))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<bool> vis(m + 1, 0);
        if (dfs(i, vis))
            ans++;
    }

    cout << ans << "\n";
    for (int i = 1; i <= m; i++)
    {
        if (match[i] != 0)
            cout << match[i] << " " << i << "\n";
    }

    return 0;
}