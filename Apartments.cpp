#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k, dem = 0;
    cin >> n >> m >> k;
    vector<int> mang1(n), mang2(m);

    for (int i = 0; i < n; i++)
    {
        cin >> mang1[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> mang2[i];
    }

    sort(mang1.begin(), mang1.end());
    sort(mang2.begin(), mang2.end());

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (mang2[j] < mang1[i] - k)
        {
            j++;
        }
        else if (mang2[j] > mang1[i] + k)
        {
            i++;
        }
        else
        {
            i++;
            j++;
            dem++;
        }
    }

    cout << dem;
}