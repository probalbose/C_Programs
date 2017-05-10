/* implement an exponentiation function */

#include <stdio.h>

float exponentiate(float base, int exponent);

int main(void)
{
    int x = 16;

    printf("%f\n", exponentiate(x,2));
    return 0;
}

float exponentiate(float base, int exponent)
{
    int i;
    float x = base;

    for(i = 1; i < exponent; i++)
        x *= x;
    return x;
}
