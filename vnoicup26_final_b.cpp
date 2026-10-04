#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int stt = 0; stt < t; stt++)
    {
        int n;
        cin >> n;

        vector<int> ar(n, 0);
        for (int i = 0; i < n; i++)
            cin >> ar[i];

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> mp;
            vector<int> val(n, 0);
            mp[ar[i]]++;
            if (ar[i] > 0)
                val[i] = 0;
            else
                val[i] = 1;

            for (int j = i + 1; j < n; j++)
            {
                mp[ar[j]]++;

                if (ar[j] == -1)
                {
                    int k = val[j - 1];
                    do
                    {
                        k++;
                    } while (mp[k] != 0);
                    val[j] = k;
                }
                else
                {
                    if (ar[j] <= val[j - 1] && mp[ar[j]] == 1)
                    {

                        int k = val[j - 1];
                        do
                        {
                            k++;
                        } while (mp[k] != 0);
                        val[j] = k;
                    }
                    else
                        val[j] = val[j - 1];
                }
            }

            for (int k = i; k < n; k++)
            {
                sum += val[k];
            }
        }
        cout << sum << endl;
    }
}
