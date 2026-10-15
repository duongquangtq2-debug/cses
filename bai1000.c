#include <stdio.h>

int main()
{
    int thang;

    printf("Nhap thang: ");
    scanf("%d", &thang);

    switch (thang)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        printf("30 ngay");
        break;
    case 2:
        printf("29 ngay");
        break;
    default:
        printf("31 ngay");
        break;
    }

    return 0;
}