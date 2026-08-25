#include <iostream>
#include <vector>
using namespace std;

string daychu;

bool xep(vector<int> &cnt, int n)
{
    if (n == 0)
    {
        cout << daychu << endl;

        return true;
    }

    for (int i = 0; i < 26; i++)
    {
        if ((daychu.empty() || daychu.back() != char('A' + i)) && cnt[i] > 0)
        {
            daychu.push_back('A' + i);
            cnt[i]--;

            if (xep(cnt, n - 1))
                return true;

            daychu.pop_back();
            cnt[i]++;
        }
    }

    return false;
}
int main()
{
    string n;
    cin >> n;
    vector<int> cnt(26, 0);
    for (char i : n)
    {
        cnt[i - 'A']++;
    }
    if (!xep(cnt, n.size()))
        cout << -1;
}