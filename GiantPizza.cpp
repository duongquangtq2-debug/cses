#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> adj[N], rev_adj[N];
bool visited[N];
int comp[N];
vector<int> order;

void dfs1(int u)
{
    visited[u] = true;

    for (int v : adj[u])
        if (!visited[v])
            dfs1(v);

    order.push_back(u);
}

void dfs2(int u, int id)
{
    comp[u] = id;

    for (int v : rev_adj[u])
        if (comp[v] == 0)
            dfs2(v, id);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        char x, y;
        int a, b;

        cin >> x >> a >> y >> b;

        int A = 2 * a + (x == '+');
        int B = 2 * b + (y == '+');

        // !A -> B
        adj[A ^ 1].push_back(B);
        rev_adj[B].push_back(A ^ 1);

        // !B -> A
        adj[B ^ 1].push_back(A);
        rev_adj[A].push_back(B ^ 1);
    }

    // DFS lần 1
    for (int i = 2; i <= 2 * m + 1; i++)
        if (!visited[i])
            dfs1(i);

    // DFS lần 2
    int cnt = 0;

    for (int i = (int)order.size() - 1; i >= 0; i--)
    {
        int u = order[i];

        if (comp[u] == 0)
        {
            ++cnt;
            dfs2(u, cnt);
        }
    }

    // Kiểm tra vô nghiệm
    for (int i = 1; i <= m; i++)
    {
        int neg = 2 * i;
        int pos = 2 * i + 1;

        if (comp[neg] == comp[pos])
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    // Lấy đáp án
    for (int i = 1; i <= m; i++)
    {
        int neg = 2 * i;
        int pos = 2 * i + 1;

        if (comp[pos] > comp[neg])
            cout << "+ ";
        else
            cout << "- ";
    }

    cout << '\n';
}