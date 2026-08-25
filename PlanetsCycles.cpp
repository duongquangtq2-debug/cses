#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int INF = -1e9;
int to[N];
vector<int> rev[N];
int dist[N];

vector<int> findCycles(int x)
{
    int a = x;
    int b = to[x];
    while (a != b)
    {
        a = to[a];
        b = to[to[b]];
    }

    vector<int> cycle;
    do
    {
        a = to[a];
        cycle.push_back(a);
    } while (a != b);
    return cycle;
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : rev[u])
        {
            if (dist[v] != INF)
                continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int u = 1; u <= n; u++)
    {
        int v;
        cin >> v;
        to[u] = v;
        rev[v].push_back(u);
        dist[u] = INF;
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
        {
            auto cycle = findCycles(i);
            for (int i = 0; i < cycle.size(); i++)
                dist[cycle[i]] = cycle.size();

            for (int i = 0; i < cycle.size(); i++)
                bfs(cycle[i]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}