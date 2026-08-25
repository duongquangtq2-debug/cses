#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 199);

    // 2.2 khoi tao mang co gia tri
    const int row = 2;
    const int col = 3;
    int mang4[row][col];
    // 2 cuat mang
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mang4[i][j] = dis(gen);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mang4[i][j] << " ";
        }
        cout << endl;
    }
}