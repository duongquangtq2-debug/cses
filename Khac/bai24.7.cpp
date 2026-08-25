#include <iostream>
#include <string>
using namespace std;

int main()
{
    char x = 'k';
    char x_hoa = toupper(x);
    cout << "Ky tu hoa cua " << x << " la: " << x_hoa << endl;

    char xx = 65;
    cout << "Ky tu tuong ung voi ma ASCII 65 la: " << xx << endl;
    cout << "ky tu trong bien xx viet hoa la: " << toupper(xx) << endl;

    char x_thuong = tolower(xx);
    cout << "ky tu trong bien xx viet thuong la: " << x_thuong << endl;

    char str1[100];

    cout << "Chuoi vua nhap la: " << str1 << endl;
    cin.getline(str1, 100);

    for (int i = 0; i < strlen(str1); i++)
    {
        str1[i] = tolower(str1[i]);
    }
    cout << "Chuoi vua nhap la: " << str1 << endl;
    for (int i = 0; i < strlen(str1); i++)
    {
        str1[i] = toupper(str1[i]);
    }
    cout << "Chuoi vua nhap la: " << str1 << endl;
}