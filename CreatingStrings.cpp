#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> dapan;
string kitu = "";
void taodapan(map<char, int> &dem, int n)
{
    if (n == 1)
    {
        for (char k = 'a'; k <= 'z'; k++)
        {
            if (dem[k] > 0)
            {
                kitu += k;
                dem[k]--;
                dapan.push_back(kitu);
                kitu.pop_back();
                dem[k]++;
            }
        }
    }
    else
    {

        for (char i = 'a'; i <= 'z'; i++)
        {

            if (dem[i] > 0)
            {
                kitu += i;
                dem[i]--;
                taodapan(dem, n - 1);
                kitu.pop_back();
                dem[i]++;
            }
        }
    }
}

int main()
{
    string daytu;
    cin >> daytu;
    map<char, int> dem;
    int n = 0;
    for (int i = 0; i < daytu.length(); i++)
    {
        dem[daytu[i]]++;
        n++;
    }

    taodapan(dem, n);
    cout << dapan.size() << endl;
    for (int i = 0; i < dapan.size(); i++)
    {
        cout << dapan[i] << endl;
    }
}