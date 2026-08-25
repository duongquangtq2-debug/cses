#include <iostream>
using namespace std;

int main()
{
    int thang, nam;
    cout << "nhap thang muon biet: ";
    cin >> thang;
    if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 10 || thang == 12 || thang == 8)
    {
        cout << "thang co 31 ngay";
    }
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
    {
        cout << "thang co 30 ngay";
    }
    else
    {
        cout << "nhap them nam: ";
        cin >> nam;
        if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
        {
            cout << "thang nay co 29 ngay";
        }
        else
        {
            cout << "thang nay co 28 ngay";
        }
    }
}