#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<vector<int>> adj(N + 1);
vector<int> state(N + 1);
vector<int> parent(N + 1);
vector<int> cycle;
int start, cur;

bool dfs(int u)
{
    state[u] = 1;
    for (auto v : adj[u])
    {
        if (state[v] == 2)
            continue;

        if (state[v] == 1)
        {
            start = v;
            parent[v] = u;
            return true;
        }

        parent[v] = u;
        if (dfs(v))
            return true;
    }

    state[u] = 2;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    bool TF = false;
    for (int i = 1; i <= n; i++)
    {
        if (state[i] != 0)
            continue;

        if (dfs(i))
        {
            TF = true;
            break;
        }
    }
    if (!TF)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cur = start;
    do
    {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != start);
    cycle.push_back(cur);
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() << endl;
    for (auto x : cycle)
        cout << x << " ";
}