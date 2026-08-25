#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        sum += t;
        if (t > mx)
            mx = t;
    }

    cout << max(sum, 2 * mx) << "\n";

    return 0;
}