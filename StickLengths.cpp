#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> lengths(n);
    for (auto &it : lengths)
    {
        cin >> it;
    }
    sort(lengths.begin(), lengths.end());
    int median = lengths[n / 2];
    long long cost = 0;
    for (auto it : lengths)
    {
        cost += abs(it - median);
    }
    cout << cost;
}