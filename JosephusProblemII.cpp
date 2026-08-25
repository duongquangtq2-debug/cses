#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;

    if (k < n)
    {
        k++;
        for (int i = 0; i < n; i++)
            v.push_back(i + 1);
        for (int i = 0; i < v.size(); i++)
        {
            if ((i + 1) % k == 0)
                cout << v[i] << " ";
            else
                v.push_back(v[i]);
        }
    }
    else
    {
        int buoccl = 0;
        set<int> s;
        for (int i = 1; i <= n; i++)
            s.insert(i);

        for (int i = 0; i < n; i++)
        {
            int sothu = (k - buoccl) % (n - i);

            auto it = s.begin();
            advance(it, sothu);
            cout << *it << " ";

            buoccl = n - i - sothu - 1;

            s.erase(it);
        }
    }
    cout << endl;
}