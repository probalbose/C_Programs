#include <stdio.h>

/* print Celsius to Fahrenheit table */

main ()
{
    float celsius, fahr;
    int lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;

    printf("%3s  %6s\n", "C", "F");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius * 1.8) + 32.0;
        printf("%3.0f  %6.2f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
