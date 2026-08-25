#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    queue<int> q;
    vector<int> ans;
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        ans.push_back(a);
        for (auto x : adj[a])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }
    if (ans.size() < n)
        cout << "IMPOSSIBLE";
    else
    {
        for (auto x : ans)
            cout << x << " ";
    }
    return 0;
}