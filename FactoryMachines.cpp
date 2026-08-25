#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

unsigned long long t;
int n;
vector<int> machine;
bool check(unsigned long long T)
{
    unsigned long long sum = 0;
    for (auto x : machine)
    {
        sum += T / x;
        if (sum >= t)
            return true;
    }
    return false;
}

int main()
{
    cin >> n >> t;

    machine.resize(n);
    int mintime = 1e9 + 1;

    for (int i = 0; i < n; i++)
    {
        cin >> machine[i];
        mintime = min(machine[i], mintime);
    }

    unsigned long long r = mintime * t;
    unsigned long long l = 0;

    while (l < r)
    {
        unsigned long long mid = l + (r - l) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l;
}