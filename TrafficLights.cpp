#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int x, n;
    cin >> x >> n;
    set<int> lights;
    multiset<int> longest;

    lights.insert(0);
    lights.insert(x);
    longest.insert(x);
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        auto it1 = lights.insert(p).first;
        auto left = prev(it1);
        auto right = next(it1);

        auto it2 = longest.find(*right - *left);
        longest.erase(it2);
        longest.insert(p - *left);
        longest.insert(*right - p);

        cout << *prev(longest.end()) << " ";
    }
}