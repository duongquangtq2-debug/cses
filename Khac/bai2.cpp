#include <iostream>
#include <cmath>
using namespace std;

bool laSoNguyenTo(int n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int dem = 0;
    int so = 1;

    while (dem < n) {
        so++;

        if (laSoNguyenTo(so))
            dem++;
    }

    cout << "So nguyen to thu " << n << " la: " << so;

    return 0;
}