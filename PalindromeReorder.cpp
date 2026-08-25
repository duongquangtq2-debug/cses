#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string kitu;
    cin >> kitu;
    vector<char> output(kitu.size());
    map<char, int> bangkt;

    for (char c : kitu)
    {
        bangkt[c]++;
    }

    int kitule = 0;

    for (int i = 0; i < bangkt.size(); i++)
    {
        auto it = bangkt.begin();

        advance(it, i);

        if (it->second % 2 == 1)
        {
            kitule++;
            output[(kitu.size()) / 2] = it->first;
            it->second--;
        }
    }

    if (kitule > 1)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        int dem = 0;
        for (int i = 0; i < bangkt.size(); i++)
        {
            auto it = bangkt.begin();

            advance(it, i);

            while (it->second > 0)
            {
                output[dem] = it->first;
                output[kitu.size() - dem - 1] = it->first;
                dem++;
                it->second -= 2;
            }
        }
        for (char c : output)
        {
            cout << c;
        }
    }
}