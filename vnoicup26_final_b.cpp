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
            vector<int> cnt(n + 9, 0);
            vector<int> val(n, 0);
            if (ar[i] <= n && ar[i] >= 0)
                cnt[ar[i]]++;

            if (ar[i] > 0)
                val[i] = 0;
            else
                val[i] = 1;

            for (int j = i + 1; j < n; j++)
            {
                if (ar[j] <= n && ar[j] >= 0)
                    cnt[ar[j]]++;

                if (ar[j] == -1)
                {
                    int k = val[j - 1];
                    do
                    {
                        k++;
                    } while (cnt[k] != 0);
                    val[j] = k;
                }
                else
                {
                    if (ar[j] <= val[j - 1] && cnt[ar[j]] == 1)
                    {
                        int k = val[j - 1];
                        do
                        {
                            k++;
                        } while (cnt[k] != 0);
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
