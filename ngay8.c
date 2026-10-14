#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    double k = d - a;
    double p = (b + c + k) / 2.0;
    double s_tam_giac = sqrt(p * (p - b) * (p - c) * (p - k));
    double h = (2 * s_tam_giac) / k;
    double dien_tich = (a + d) * h / 2.0;

    printf("%.2lf\n", dien_tich);

    return 0;
}