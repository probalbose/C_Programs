/* Write a program that computes the factorial of a positive integer */

#include <stdio.h>

int main(void) {
    int input, i;
    long double result;

    printf("enter a positive integer: ");
    scanf("%d", &input);

    result = (long double) input;

    for (i = input - 1; i > 0; i--)
        result *= i;

    printf("factorial of %d: %Lf\n", input, result);

    return 0;
}
