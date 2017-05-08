// Prompt user for start temperature, end temperature, & step size. 
// List temperatures between start and end at steps given by step size.
// List temperatures in Celsius and Fahrenheit.

#include <stdio.h>

#define LOWER_LIMIT 0
#define UPPER_LIMIT 1000

int main(void)
{
    float lower, upper, step_size, i;

    printf("Enter a lower limit such that limit > 0: ");
    scanf("%f", &lower);
    printf("Enter an upper limit such that limit < 1000: ");
    scanf("%f", &upper);
    printf("Enter a step size: ");
    scanf("%f", &step_size);

    if(step_size > (upper - lower))
    {
        printf("Step size is greater than difference between upper and lower bound.\n");
        return 1;
    }
    else if(lower > upper)
    {
        printf("Lower bound is greater than upper bound.\n");
        return 1;
    }
    else if(lower < 0)
    {
        printf("Lower bound is lower than 0.\n");
        return 1;
    }
    else if(upper > 1000)
    {
        printf("Upper bound is higher than 1000.\n");
        return 1;
    }

    printf("Celsius:\t\tFahrenheight:\t\t\n");
    printf("_ _ _ _ \t\t_ _ _ _ _ _ _\n\n");

    for(i = lower; i < upper; i += step_size)
    {
        printf("%.2f\t\t%.2f\n", i, i*1.8+32);
    }
    return 0;
}
