#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long reward = 0, sum = 0;
    cin >> n;
    vector<int> time(n);
    for (int i = 0; i < n; i++)
    {
        int deadline;
        cin >> time[i] >> deadline;
        reward += deadline - time[i];
    }
    sort(time.begin(), time.end());
    for (int i = 0; i < n; i++)
    {
        reward -= sum;
        sum += time[i];
    }

    cout << reward;
}