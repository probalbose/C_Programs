#include <stdio.h>

/* display Fahrenheit-Celsius table
 *
 * DOMAIN ANALYSIS
 * Scenarios
 * - program prints Fahrenheit values 0, 20, ..., 300 and 
 *   corresponding Celsius values
 *   i.e.
 *      F   C
 *      0 -14
 *      20 83
 *      40 8280
 *      ...
 *
 *
 * Constants
 * - lower bound, 0 degrees
 * - upper bound, 300 degrees
 * - step size, 20 degrees
 *
 *
 * Changing Data
 * - corresponding degree value in Celsius
 *   - pass F to a function to get C
 *
 *
 * Main Function
 * - each line prints Fahrenheit-Celsius value pair
 *   - will need to pass Fahrenheit value to a function
 *     that returns the corresponding value in Celsius
 */

#define LOWER 0
#define UPPER 300
#define STEP 20

float toc(int f);

main ()
{
    int fahr;

    fahr = 0;
    printf("%3s %6s\n", "F", "C");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%3d %6.1f\n", fahr, toc(fahr));
    }
}

/* Int -> Float
 * produce Celsius value = to the consumed Fahrenheit value
 */
float toc(int fahr)
{
    return ((5.0 / 9.0) * (fahr - 32.0));
}





