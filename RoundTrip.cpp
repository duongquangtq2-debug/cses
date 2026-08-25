#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int n, m;
int cycleStart, cycleEnd;

vector<vector<int>> road(maxn);
vector<bool> vis(maxn, false);
vector<int> parent(maxn);

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
}

bool dfs(int a)
{
    vis[a] = true;
    for (auto b : road[a])
    {
        if (!vis[b])
        {
            parent[b] = a;
            if (dfs(b))
                return true;
        }
        else
        {
            if (b != parent[a])
            {
                cycleStart = b;
                cycleEnd = a;
                return true;
            }
        }
    }
    return false;
}

void print()
{
    vector<int> ans = {cycleStart};

    for (int x = cycleEnd; x != cycleStart; x = parent[x])
        ans.push_back(x);

    ans.push_back(cycleStart);

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " ";
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
            if (dfs(a))
            {
                print();
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}