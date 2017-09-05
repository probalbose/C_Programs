/*
 * compute 3x**5 + 2x**4 - 5x**3 - x**2 + 7x - 6
 */

#include <stdio.h>
#include <math.h>

double compute_poly(double x);

int main(void) {
    double value;

    printf("enter a value for x: ");
    scanf(" %lf", &value);

    printf("the value of the polynomial is %lf\n", compute_poly(value));
    return 0;
}

double compute_poly(double x) {
    double result = 0;

    result += 3 * pow(x, 5);
    result += 2 * pow(x, 4);
    result -= 5 * pow(x, 3);
    result -= pow(x, 2);
    result += 7 * x;
    result -= 6;

    return result;
}
    
