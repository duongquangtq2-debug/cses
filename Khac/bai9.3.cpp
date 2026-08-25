#include <iostream>
using namespace std;

int main()
{
    double chieucao, cannang, bmi;
    cout << "Nhap chieu cao (m): ";
    cin >> chieucao;
    cout << "Nhap can nang (kg): ";
    cin >> cannang;

    bmi = cannang / pow(chieucao, 2);
    cout << "BMI cua ban la: " << bmi << endl;

    if (bmi < 15)
    {
        cout << "Than hinh cua ban qua gay" << endl;
    }
    else if (bmi >= 15 && bmi < 16)
    {
        cout << "Than hinh gay" << endl;
    }
    else if (bmi >= 16 && bmi < 18.5)
    {
        cout << "Than hinh thieu can" << endl;
    }
    else if (bmi >= 18.5 && bmi < 25)
    {
        cout << "Than hinh binh thuong" << endl;
    }
    else if (bmi >= 25 && bmi < 30)
    {
        cout << "Than hinh thua can" << endl;
    }
    else if (bmi >= 30 && bmi < 35)
    {
        cout << "Than hinh beo phi cap do I" << endl;
    }
    else if (bmi >= 35 && bmi < 40)
    {
        cout << "Than hinh beo phi cap do II" << endl;
    }
    else
    {
        cout << "Than hinh beo phi cap do III" << endl;
    }
}