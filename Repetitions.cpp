#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int dem = 1;
    string n;
    cin >> n;

    vector<char> kitu(n.length());
    vector<int> sokitu(n.length(), 1);

    for (int i = 0; i < n.length(); i++)
    {
        kitu[i] = n[i];
    }

    for (int i = 0; i < (n.length() - 1); i++)
    {
        if (kitu[i] == kitu[i + 1])
        {
            sokitu[i + 1] = sokitu[i + 1] + sokitu[i];
        }
    }

    int hsmax = sokitu[0];
    for (int i = 1; i < n.length(); i++)
    {
        if (sokitu[i] > hsmax)
        {
            hsmax = sokitu[i];
        }
    }
    cout << hsmax;
}