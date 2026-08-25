#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    const int toida = 15;

    char kytu[5] = {'a', 'b', 'c', 'd'};
    cout << kytu << endl;

    char chuoi[] = "xinchao";
    cout << chuoi << endl;
    cout << strlen(chuoi);

    cout << endl;

    char chuoikt[toida];
    cin.getline(chuoikt, toida);
    cout << chuoikt;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char *chuoi4;
    chuoi4 = new char[toida];
    cin.getline(chuoi4, toida);
    cout << chuoi4;
}