#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<bool> children(n + 1, true);
    bool tf = false;
    int dem = 0;
    while (dem < n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (children[i])
            {
                if (tf)
                {
                    dem++;
                    children[i] = false;
                    cout << i << " ";
                }
                tf = !tf;
            }
        }
    }
}