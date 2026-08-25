#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, stt = 1;
    cin >> n;
    if (n == 3 || n == 2)
    {
        cout << "NO SOLUTION";
    }
    else if (n == 4)
    {
        cout << "3 1 4 2";
    }
    else
    {
        vector<int> N(n);
        for (int i = 0; i < n; i += 2)
        {
            N[i] = stt;
            stt++;
        }

        for (int i = 1; i < n; i += 2)
        {
            N[i] = stt;
            stt++;
        }

        for (int pt : N)
        {
            cout << pt << " ";
        }
    }
}