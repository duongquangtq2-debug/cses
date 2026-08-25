#include <iostream>
using namespace std;

int main()
{
    double a, b, c;
    cout << "nhap ba so a,b,c: ";
    cin >> a >> b >> c;

    if (a == b)
    {
        if (b == c)
        {
            cout << "so lon nhat la: " << a << endl;
            cout << "so nho nhat la: " << a << endl;
            cout << "ba so bang nhau" << endl;
            cout << "khong co dung hai so bang nhau" << endl;
        }
        else if (b > c)
        {
            cout << "so lon nhat la: " << a << endl;
            cout << "so nho nhat la: " << c << endl;
            cout << "khong co ba so bang nhau" << endl;
            cout << "co dung hai so bang nhau" << endl;
        }
        else
        {
            cout << "so lon nhat la: " << c << endl;
            cout << "so nho nhat la: " << a << endl;
            cout << "khong co ba so bang nhau" << endl;
            cout << "co dung hai so bang nhau" << endl;
        }
    }
    else if (a > b)
    {
        if (b == c)
        {
            cout << "so lon nhat la: " << a << endl;
            cout << "so nho nhat la: " << b << endl;
            cout << "khong co ba so bang nhau" << endl;
            cout << "co dung hai so bang nhau" << endl;
        }
        else if (b > c)
        {
            cout << "so lon nhat la: " << a << endl;
            cout << "so nho nhat la: " << c << endl;
            cout << "khong co ba so bang nhau" << endl;
            cout << "khong co dung hai so bang nhau" << endl;
        }
        else
        {
            if (a >= c)
            {
                cout << "so lon nhat la: " << a << endl;
                cout << "so nho nhat la: " << b << endl;
                cout << "khong co ba so bang nhau" << endl;
                cout << "khong co dung hai so bang nhau" << endl;
            }
            else
            {
                cout << "so lon nhat la: " << c << endl;
                cout << "so nho nhat la: " << b << endl;
                cout << "khong co ba so bang nhau" << endl;
                cout << "khong co dung hai so bang nhau" << endl;
            }
        }
    }
    else
    {
        if (b == c)
        {
            cout << "so lon nhat la: " << b << endl;
            cout << "so nho nhat la: " << a << endl;
            cout << "khong co ba so bang nhau" << endl;
            cout << "co dung hai so bang nhau" << endl;
        }
        else if (b > c)
        {
            if (c >= a)
            {
                cout << "so lon nhat la: " << b << endl;
                cout << "so nho nhat la: " << a << endl;
                cout << "khong co ba so bang nhau" << endl;
                cout << "khong co dung hai so bang nhau" << endl;
            }
            else
            {
                cout << "so lon nhat la: " << b << endl;
                cout << "so nho nhat la: " << c << endl;
                cout << "khong co ba so bang nhau" << endl;
                cout << "khong co dung hai so bang nhau" << endl;
            }
        }
        else
        {
            cout << "so lon nhat la: " << c << endl;
            cout << "so nho nhat la: " << a << endl;
            cout << "khong co ba so bang nhau" << endl;
            cout << "khong co dung hai so bang nhau" << endl;
        }
    }
}