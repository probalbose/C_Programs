// Calculate check digit of a UPC code

#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11;
    int sum1, sum2, result = 0;
    printf("Enter first 11 digits of a UPC code: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6, 
            &i7, &i8, &i9, &i10, &i11);

    sum1 = i1 + i3 + i5 + i7 + i9 + i11;
    sum2 = i2 + i4 + i6 + i8 + i10;
    result = (sum1 * 3) + sum2;
    result -= 1;
    result %= 10;
    result = 9 - result;

    printf("Check digit: %d\n", result);
    return 0;
}
