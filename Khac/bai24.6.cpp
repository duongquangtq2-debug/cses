#include <iostream>
#include <string>
using namespace std;

int main()
{
    char str9[] = "helloa";
    char str10[] = "helloA";

    int kq = strcmp(str9, str10);

    cout << "So sanh 2 chuoi: " << kq << endl;
}