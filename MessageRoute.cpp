#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int n, m;

vector<vector<int>> adj(maxn);
vector<bool> vis(maxn, false);
vector<int> parent(maxn);
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    nhap();

    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int j : adj[x])
        {
            if (!vis[j])
            {
                vis[j] = true;
                parent[j] = x;
                q.push(j);
            }
        }
    }
    if (vis[n])
    {
        vector<int> ans;
        ans.push_back(n);
        while (ans.back() != 1)
        {
            ans.push_back(parent[ans.back()]);
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x << " ";
    }
    else
        cout << "IMPOSSIBLE";

    return 0;
}