#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> bang;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        bang[x]++;
    }
    cout << bang.size();
}