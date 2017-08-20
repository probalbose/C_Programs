/*
Sum a series of numbers using double variables
*/

#include <stdio.h>

int main(void) {
    double n, sum = 0;

    printf("this program sums a series of doubles\n");
    printf("enter doubles (0 to terminate): ");
    scanf("%lf", &n);
    while (n != 0.0L) {
        sum += n;
        scanf("%lf", &n);
    }
    printf("the sum is %lf\n", sum);
    
    return 0;
}
