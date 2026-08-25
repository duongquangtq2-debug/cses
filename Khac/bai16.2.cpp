#include <iostream>
#include <cmath>
using namespace std;

bool songuyento(int x)
{
    if (x < 2)
    {
        return false;
    }
    else
    {
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int vietnguoc(int x)
{
    int somoi = 0;
    for (int i = x; i > 0; i = i / 10)
    {
        somoi = somoi * 10 + i % 10;
    }
    return somoi;
}

int tongcs(int x)
{
    int tongcs = 0;
    for (int i = x; i > 0; i = i / 10)
    {
        tongcs = tongcs + (i % 10);
    }
    return tongcs;
}

bool ktcs0(int x)
{
    bool kq = true;
    if (x == 0)
        return false;

    for (int i = x; i > 0; i = i / 10)
    {
        if (i % 10 == 0)
        {
            kq = false;
            break;
        }
    }
    return kq;
}

bool solgcs(int x)
{
    int i = log10(x) + 1;
    if (i % 2 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a, b;
    cout << "Nhap hai so a b: ";
    cin >> a >> b;
    cout << "so thoa man la: ";
    for (int i = a; i <= b; i++)
    {
        if (songuyento(i) && songuyento(tongcs(i)) && songuyento(vietnguoc(i)) && solgcs(i) && ktcs0(i))
        {
            cout << i << " ";
        }
    }
}