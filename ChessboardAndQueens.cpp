#include <iostream>
using namespace std;
int soth = 0;
bool checkvitri(int (&bancoint)[8][8], int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        if (i != y && bancoint[x][i] == 1)
        {
            return false;
        }
        if (i != x && bancoint[i][y] == 1)
        {
            return false;
        }
    }

    int a1, b1, a2, b2;
    if (y - x <= 7 && y - x >= 0)
    {
        a1 = 0;
        b1 = 7 - (y - x);
    }
    else
    {
        a1 = x - y;
        b1 = 7;
    }

    if (y + x <= 7 && y + x >= 0)
    {
        a2 = 0;
        b2 = x + y;
    }
    else
    {
        a2 = x + y - 7;
        b2 = 7;
    }

    for (int i = a1; i <= b1; i++)
    {
        if (i != x && bancoint[i][y - x + i] == 1)
        {
            return false;
        }
    }
    for (int i = a2; i <= b2; i++)
    {
        if (i != x && bancoint[i][y + x - i] == 1)
        {
            return false;
        }
    }

    return true;
}

void xetvitri(int (&bancoint)[8][8], int hang)
{
    if (hang == -1)
    {
        soth++;
    }
    else
    {
        for (int i = 0; i <= 7; i++)
        {
            if (bancoint[hang][i] == 0 && checkvitri(bancoint, hang, i))
            {
                bancoint[hang][i] = 1;
                xetvitri(bancoint, hang - 1);
                bancoint[hang][i] = 0;
            }
        }
    }
}

int main()
{
    char banco[8][8];
    int bancoint[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> banco[i][j];
            if (banco[i][j] == '.')
            {
                bancoint[i][j] = 0;
            }
            else if (banco[i][j] == '*')
            {
                bancoint[i][j] = 2;
            }
        }
        cout << endl;
    }

    xetvitri(bancoint, 7);

    cout << soth;
}
