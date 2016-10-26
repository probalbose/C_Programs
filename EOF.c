#include <stdio.h>

/* verify that (getchar() != EOF) is either 0 or 1 */

/*
==================
DOMAIN ANALYSIS

Scenarios: program prints value of the expression (getchar() != EOF)

Constants: --
Variables: c = (getchar() != EOF) 

*/

main ()
{
    int c;

    c = (getchar() != EOF);
    printf("%d\n", c);
}
