#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int> lasts;
    int left = 0;
    long long round = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if (lasts[x] != 0)
        {
            left = max(lasts[x], left);
        }
        round += i - left;

        lasts[x] = i;
    }
    cout << round;
}
