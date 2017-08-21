/* Write a program that computes the factorial of a positive integer */

#include <stdio.h>

int main(void) {
    int input, i;
    int result;

    printf("enter a positive integer: ");
    scanf("%d", &input);

    result = input;

    for (i = input - 1; i > 0; i--)
        result *= i;

    printf("factorial of %d: %d\n", input, result);

    return 0;
}
