#include <iostream>

int main()
{
    float dtb;
    std::cout << "Nhap diem trung binh: ";
    cin >> dtb;
    if (dtb >= 5.0)
        cout << "Ban da do" << endl;
    else
        cout << "Ban da truot" << endl;
}