#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    /*
    char str1[100], str2[100];
    cin >> str1;
    cin >> str2;

    strncat(str1, str2, 3);

    cout << str1 << endl;
    */

    char *thutu;
    char kytux[100];
    char str7[100];

    cout << "Nhap chuoi: ";
    cin >> str7;
    cout << "Nhap chuoi can tim: ";
    cin >> kytux;

    thutu = strstr(str7, kytux);

    if (thutu == NULL)
    {
        cout << "Khong tim thay chuoi" << endl;
    }
    else
    {
        cout << "Chuoi " << kytux << " xuat hien trong chuoi tai vi tri " << thutu - str7 << endl;
    }
}