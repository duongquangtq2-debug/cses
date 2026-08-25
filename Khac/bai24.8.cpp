#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[100];
    cin.getline(str1, 100);
    for (int i = 0; str1[i] != '\0'; i++)
    {
        int maasii = (int)str1[i];
        cout << maasii << " ";
    }
    cout << endl;

    reverse(str1, str1 + strlen(str1));
    cout << "Chuoi dao nguoc la: " << str1 << endl;
}