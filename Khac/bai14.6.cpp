#include <iostream>
using namespace std;

int main()
{
    int luachon = -1;
    double a, b;
    while (luachon != 0)
    {
        cout << "======MAY TINH======" << endl;
        cout << "1. Cong" << endl;
        cout << "2. Tru" << endl;
        cout << "3. Nhan" << endl;
        cout << "4. Chia" << endl;
        cout << "0. Thoat" << endl;
        cout << "Moi nhap lua chon: ";
        cin >> luachon;

        switch (luachon)
        {
        case 1:
            cout << "Moi nhap 2 so a, b:";
            cin >> a >> b;
            cout << "Ket qua: " << a + b << endl;
            break;
        case 2:
            cout << "Moi nhap 2 so a, b:";
            cin >> a >> b;
            cout << "Ket qua: " << a - b << endl;
            break;
        case 3:
            cout << "Moi nhap 2 so a, b:";
            cin >> a >> b;
            cout << "Ket qua: " << a * b << endl;
            break;
        case 4:
            cout << "Moi nhap 2 so a, b:";
            cin >> a >> b;
            if (b == 0)
            {
                cout << "Phep tinh khong hop le" << endl;
            }
            else
            {
                cout << "Ket qua: " << a / b << endl;
            }
            break;

        case 0:
            cout << "Tam biet!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }
    }
}