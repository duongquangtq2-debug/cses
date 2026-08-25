#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double diemtoan, diemvan, diemanh, dtb;
    cout << " Moi nhap diem toan: ";
    cin >> diemtoan;
    cout << " Moi nhap diem van: ";
    cin >> diemvan;
    cout << " Moi nhap diem anh: ";
    cin >> diemanh;

    dtb = (diemtoan + diemvan + diemanh) / 3;
    cout << "Diem trung binh: " << dtb << endl;
    cout << " Diem trung binh sau khi lam tron: " << setprecision(3) << fixed << dtb << endl;
}