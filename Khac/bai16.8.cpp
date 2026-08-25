#include <iostream>
using namespace std;

const int solon = 100000;

bool N[solon + 1];
void sang(int n)
{

    for (int i = 0; i <= solon; i++)
    {
        N[i] = true;
    }

    for (int k = 2; k * k <= solon; k++)
    {
        if (N[k])
        {
            for (int j = k * k; j <= solon; j += k)
            {
                N[j] = false;
            }
        }
    }
}

int souoc(int n)
{
    int nhapuoc = 1;
    int hangson = n;
    for (int i = 2; i * i <= hangson; i++)
    {

        if (N[i])
        {
            int dem = 0;

            while (hangson % i == 0)
            {

                dem++;
                hangson = hangson / i;
            }

            if (dem >= 1)
            {
                nhapuoc = nhapuoc * (dem + 1);
            }
        }
    }

    if (hangson > 1)
    {
        nhapuoc *= 2;
    }

    return nhapuoc;
}

int main()
{
    sang(solon + 1);
    int souocmax = 0, sodo = 0;
    int a, b;
    cout << "nhap a, b: ";
    cin >> a >> b;
    for (int k = a; k <= b; k++)
    {
        if (souoc(k) > souocmax)
        {
            souocmax = souoc(k);
            sodo = k;
        }
    }
    cout << "max la " << sodo << " co " << souocmax << " uoc";
}