#include <iostream>
using namespace std;

int main()
{
    int n, i = 1, souoc = 0;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    while (i <= n)
    {
        if (n % i == 0)
        {
            souoc += 1;
        }
        i++;
    }
    cout << "So uoc la: " << souoc;
}