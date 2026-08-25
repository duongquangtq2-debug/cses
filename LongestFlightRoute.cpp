#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    queue<int> q;
    vector<int> dp(n + 1);
    dp[1] = 1;
    vector<int> parent(n + 1);
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
        int x = q.front();
        q.pop();
        for (auto y : adj[x])
        {
            if (dp[x] != 0 && dp[y] < dp[x] + 1)
            {
                parent[y] = x;
                dp[y] = dp[x] + 1;
            }
            indegree[y]--;
            if (indegree[y] == 0)
                q.push(y);
        }
    }

    if (dp[n] == 0)
        cout << "IMPOSSIBLE";
    else
    {
        cout << dp[n] << endl;
        vector<int> ans;
        ans.push_back(n);
        while (*ans.rbegin() != 1)
            ans.push_back(parent[*ans.rbegin()]);
        reverse(ans.begin(), ans.end());
        for (auto x : ans)
            cout << x << " ";
    }

    return 0;
}