#include <iostream>
using namespace std;

void maytinh(double a, double b, char dautinh)
{
    double kq;
    if (dautinh == '+')
    {
        kq = a + b;
    }
    else if (dautinh == '-')
    {
        kq = a - b;
    }
    else if (dautinh == '*')
    {
        kq = a * b;
    }
    else if (dautinh == '/')
    {
        if (b == 0)
        {
            cout << "loi";
        }
        else
        {
            kq = a / b;
        }
    }
    else
    {
        cout << "linh tinh";
    }
    cout << "kq=" << kq;
}

int main()
{
    double a, b;
    char dautinh;
    cout << "Moi nhap a b: ";
    cin >> a >> b;
    cout << "Moi nhap dau tinh: ";
    cin >> dautinh;
    maytinh(a, b, dautinh);
}