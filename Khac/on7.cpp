#include <iostream>
using namespace std;

int main()
{
    int soHang;

    cout << "Nhap so hang: ";
    cin >> soHang;

    for (int dong = 1; dong <= soHang; dong++)
    {
        // In khoảng trắng
        for (int khoangTrang = 1; khoangTrang <= soHang - dong; khoangTrang++)
        {
            cout << " ";
        }

        // In dấu *
        for (int dauSao = 1; dauSao <= 2 * dong - 1; dauSao++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}