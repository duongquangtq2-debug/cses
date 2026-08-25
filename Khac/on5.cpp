#include <iostream>
using namespace std;

int main()
{
    int n, j = 1;
    cout << "Moi nhap so hang n: ";
    cin >> n;
    while (j <= n)
    {
        for (int i = 1; i <= j; i++)
        {
            cout << "*";
        }
        j++;
        cout << endl;
    }
}
