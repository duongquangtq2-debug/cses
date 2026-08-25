#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 200000 + 1;
int n, q, tt = 0;
int dp[N][30];
int vis[N];
int cycle_id[N];
int pos_[N];
vector<int> cycle_size;
int depth_[N];
int entry_[N];
vector<int> rev_[N];

void dfs(int x)
{
    if (vis[x] == 1)
    {
        cycle_size.push_back(1);
        pos_[x] = 0;
        cycle_id[x] = tt;

        int id = 1;
        int cur = dp[x][0];
        while (cur != x)
        {
            pos_[cur] = id++;
            cycle_id[cur] = tt;
            cycle_size[tt]++;
            cur = dp[cur][0];
        }
        tt++;
        return;
    }
    else if (vis[x] == 2)
    {
        return;
    }
    vis[x] = 1;
    dfs(dp[x][0]);
    vis[x] = 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i][0];
        rev_[dp[i][0]].push_back(i);
    }

    for (int i = 1; i < 30; i++)
        for (int j = 1; j <= n; j++)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];

    for (int i = 1; i <= n; i++)
    {
        cycle_id[i] = -1;
        pos_[i] = -1;
        depth_[i] = -1;
        entry_[i] = -1;
    }

    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs(i);

    queue<int> bfs_queue;
    for (int i = 1; i <= n; i++)
    {
        if (cycle_id[i] != -1)
        {
            depth_[i] = 0;
            entry_[i] = i;
            bfs_queue.push(i);
        }
    }
    while (!bfs_queue.empty())
    {
        int x = bfs_queue.front();
        bfs_queue.pop();

        for (auto y : rev_[x])
        {
            if (cycle_id[y] != -1)
                continue;

            depth_[y] = depth_[x] + 1;
            entry_[y] = entry_[x];

            bfs_queue.push(y);
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        // TH1: a nam tren mot chu trinh
        if (cycle_id[a] != -1)
        {
            if (cycle_id[a] == cycle_id[b])
            {
                int sz = cycle_size[cycle_id[a]];
                int buoc = (pos_[b] - pos_[a] + sz) % sz;
                cout << buoc << endl;
            }
            else
                cout << -1 << endl;
            continue;
        }

        if (cycle_id[a] == -1 && cycle_id[b] == -1 && entry_[a] == entry_[b] && depth_[a] >= depth_[b])
        {
            int buoc = depth_[a] - depth_[b];
            int ans = a;
            for (int i = 0; i < 30; i++)
            {
                if (buoc & (1 << i))
                {
                    ans = dp[ans][i];
                }
            }
            if (ans == b)
                cout << buoc << endl;
            else
                cout << -1 << endl;
            continue;
        }
        if (cycle_id[a] == -1 && cycle_id[b] != -1 && cycle_id[entry_[a]] == cycle_id[b])
        {
            int buoc = depth_[a];
            buoc += (pos_[b] - pos_[entry_[a]] + cycle_size[cycle_id[b]]) % cycle_size[cycle_id[b]];
            cout << buoc << endl;
            continue;
        }
        cout << -1 << endl;
    }
    return 0;
}