#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    for (auto &a : x)
        cin >> a;
    vector<int> tail;
    for (auto a : x)
    {
        auto it = lower_bound(tail.begin(), tail.end(), a);
        if (it == tail.end())
            tail.push_back(a);
        else
            *it = a;
    }
    cout << tail.size();
    return 0;
}