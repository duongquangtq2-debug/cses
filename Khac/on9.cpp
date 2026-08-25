#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Moi nhap vao so tu nhien n: ";
    cin >> n;
    for (int songuyen = 2; songuyen <= n; songuyen++)
    {
        bool songuyento = true;
        for (int uoc = 2; uoc <= sqrt(songuyen); uoc++)
        {
            if (songuyen % uoc == 0)
            {
                songuyento = false;
                break;
            }
        }
        if (songuyento)
        {
            cout << songuyen << endl;
        }
    }
}
