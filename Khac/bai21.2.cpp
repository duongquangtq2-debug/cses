#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    int mang[7];

    for (int i = 0; i < 7; i++)
    {
        mang[i] = dis(gen);
    }
    for (int pt : mang)
    {
        cout << pt << " ";
    }
    cout << endl;

    reverse(mang, mang + 7);
    for (int pt : mang)
    {
        cout << pt << " ";
    }
    cout << endl;

    sort(mang, mang + 7);
    for (int pt : mang)
    {
        cout << pt << " ";
    }
    cout << endl;

    int tongpt = 0;
    for (int pt : mang)
    {
        tongpt += pt;
    }
    cout << "Tong cac phan tu: " << tongpt << endl;

    int a;
    cin >> a;
    for (int i = 0; i < 7; i++)
    {
        if (mang[i] == a)
        {
            cout << "Phan tu " << a << " co trong mang" << endl;
        }
    }
}