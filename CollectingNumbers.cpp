#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, ans = 1, num = 1;
    cin >> n;
    vector<int> dayso(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dayso[x - 1] = num++;
    }

    for (int i = 1; i < n; i++)
    {
        if (dayso[i - 1] > dayso[i])
        {
            ans++;
        }
    }
    cout << ans;
}
