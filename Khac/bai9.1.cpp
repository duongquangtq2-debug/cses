#include <iostream>
using namespace std;

int main()
{
    float dtb2;
    std::cout << "Nhap diem trung binh: ";
    cin >> dtb2;
    if (dtb2 >= 9.0 && dtb2 <= 10)
    {
        cout << "Ban dat hsg" << endl;
    }
    else if (dtb2 >= 7.0 && dtb2 < 9.0)
    {
        cout << "Ban dat kha" << endl;
    }
    else if (dtb2 >= 5.0 && dtb2 < 7.0)
    {
        cout << "Ban dat trung binh" << endl;
    }
    else
    {
        cout << "Ban da truot" << endl;
    }
}