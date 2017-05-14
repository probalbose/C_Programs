/* ask user for value of x and return the result of the polynomial
 * 3x**5 + 2x**4 - 5x**3 - x**2 + 7x - 6 */

#include <stdio.h>

float exponentiate(float base, int exponent);

int main(void)
{
    float x;
    
    printf("Enter a value for x: ");
    scanf("%f", &x);

    printf("%f\n", ((3 * exponentiate(x, 5)) + (2 * exponentiate(x, 4))
                - (5 * exponentiate(x, 3)) - (exponentiate(x, 2)) - (7 * x) - 6));

    return 0;
}

float exponentiate(float base, int exponent)
{
    int i;
    float result = base;

    for(i = 1; i < exponent; i++)
        result *= base;

    return result;
}
