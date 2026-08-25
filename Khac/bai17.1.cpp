#include <iostream>
using namespace std;

int cong(int x, int y)
{
    return x + y;
}
void xinchao(string gioitinh)
{
    if (gioitinh == "nu")
    {
        cout << "xin chao nu" << endl;
    }
    else if (gioitinh == "nam")
    {
        cout << "xin chao nam" << endl;
    }
}

int main()
{
    int kq = cong(10, 100);
    cout << kq << endl;
    xinchao("nu");
    xinchao("nam");
}
