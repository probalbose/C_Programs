/* Use Newton's method to compute the square root of a positive floating-point number x. */

#include <stdio.h>
#include <math.h>

int main(void) {
    double x, y = 1.0L, average;

    printf("enter a number: ");
    scanf("%lf", &x);

    average = ((x / y) + y) / 2;

    while (fabs(average - y) > (y * 0.00001)) {
        y = average;
        average = ((x / y) + y) / 2;
    }

    printf("square root: %lf\n", average);

    return 0;
}
