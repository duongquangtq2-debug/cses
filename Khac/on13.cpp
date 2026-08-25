#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, dem1 = 0, dem2 = 0, hsmax = 0;
    cin >> n;

    vector<int> N(n);
    vector<bool> TF(n, true);
    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (TF[i])
        {
            for (int j = i + 1; j < n; j++)
            {
                if (N[i] == N[j])
                {
                    TF[j] = false;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (TF[i])
        {
            dem1++;
        }
    }

    vector<int> sau(dem1), hs(dem1);

    for (int i = 0; i < n; i++)
    {
        if (TF[i])
        {
            sau[dem2] = N[i];
            dem2++;
        }
    }

    for (int i = 0; i < dem2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sau[i] == N[j])
            {
                hs[i] += 1;
            }
        }
    }

    for (int i = 0; i < dem2; i++)
    {
        if (hs[i] >= hsmax)
        {
            hsmax = hs[i];
        }
    }

    for (int i = 0; i < dem2; i++)
    {
        if (hs[i] == hsmax)
        {
            cout << "so " << sau[i] << " co he so max la: " << hs[i] << endl;
        }
    }
}