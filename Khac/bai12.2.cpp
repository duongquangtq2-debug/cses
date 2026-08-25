#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    int n;
    cout << "Moi nhap vao so tu nhien n: ";
    cin >> n;
    int sochuso = (floor(log10(n)) + 1);
    cout << "So chu so cua n la: " << sochuso;
}