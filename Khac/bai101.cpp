2
#include <iostream>
using namespace std;

int main()
{
    // khai bao n
    double diem;
    cout << "Moi nhap vao so nguyen diem: ";
    cin >> diem;

    string xeploai = (diem >= 8)     ? "gioi"
                     : (diem >= 6.5) ? "kha"
                     : (diem >= 5)   ? "trung binh"
                                     : "yeu";

    cout << xeploai;
}