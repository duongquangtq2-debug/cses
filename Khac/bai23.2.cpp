#include <iostream>
using namespace std;

int main()
{

    int nhietdo = 70;
    cout << &nhietdo << endl;

    int *controt;
    controt = &nhietdo;
    cout << controt << endl;
    cout << *controt << endl;

    *controt = 10;
    cout << nhietdo << endl;

    void *gicungduoc;
    gicungduoc = &nhietdo;
    cout << *(int *)gicungduoc << endl;

    int mang[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int *contromang;
    contromang = mang;
    int n = sizeof(mang) / sizeof(mang[0]);
    for (int i = 0; i < n; i++)
    {
        cout << *(contromang + i) << " ";
    }

    int *mangcontro1[10];

    for (int i = 0; i < 10; i++)
    {
        mangcontro1[i] = new int;
    }

    for (int i = 0; i < 10; i++)
    {
        *mangcontro1[i] = i;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << *mangcontro1[i] << " ";
    }

    const int dong = 3;
    const int cot = 4;
    int **caphai = new int *[dong];
    for (int i = 0; i < dong; i++)
    {
        *(caphai + i) = new int[cot];
    }

    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << &caphai[i][j] << " ";
        }
        cout << endl;
    }
}