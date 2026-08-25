#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Moi nhap so hang n: ";
    cin >> n;
    while (n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "*";
        }
        n--;
        cout << endl;
    }
}
