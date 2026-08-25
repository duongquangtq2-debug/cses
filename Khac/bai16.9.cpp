#include <iostream>
using namespace std;

int main()
{
    int a, YN = 1;

    while (YN != 0)
    {
        cout << "Moi nhap vao so a: ";
        cin >> a;
        bool songuyento = true;

        while (a < 0)
        {
            cout << "Moi nhap vao so nguyen a > 0" << endl;
            cout << "Moi nhap vao so a: ";
            cin >> a;
        }

        if (a < 2)
        {
            songuyento = false;
        }
        else
        {

            for (int n = 2; n * n <= a; n++)
            {
                if (a % n == 0)
                {
                    songuyento = false;
                    break;
                }
            }
        }

        if (songuyento)
        {
            cout << "Day la so nguyen to" << endl;
        }
        else
        {
            cout << "Day khong phai so nguyen to" << endl;
        }
        cout << "Ban co muon tiep tuc khong YN: " << endl;
        cin >> YN;
    }
}