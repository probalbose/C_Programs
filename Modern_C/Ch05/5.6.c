/* check if upc code is valid */

#include <stdio.h>

int main(void) {
    int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,check_digit,sum1,sum2,result;

    printf("Enter first single digit: ");
    scanf("%1d", &d1);
    
    printf("Enter first group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &d2, &d3, &d4, &d5, &d6);
    printf("Enter second group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &d7, &d8, &d9, &d10, &d11);
    printf("Enter check digit: ");
    scanf("%1d", &check_digit);

    sum1 = d1 + d3 + d5 + d7 + d9 + d11;
    sum2 = d2 + d4 + d6 + d8 + d10;

    result = 9 - ((((3 * sum1) + sum2) - 1) % 10);

    if (result == check_digit)
        printf("VALID\n");
    else
        printf("INVALID\n");

    return 0;
}
