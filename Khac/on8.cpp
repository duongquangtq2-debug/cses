#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Kich thuoc cua bang n: ";
    cin >> n;
    for (int hang = 1; hang <= n; hang++)
    {
        for (int cot = 1; cot <= n; cot++)
        {
            cout << (cot * hang) << " ";
        }
        cout << endl;
    }
}
