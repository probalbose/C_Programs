#include <stdio.h>

/* print the value of EOF */

/*
domain analysis

Scenarios: when called, the program prints the value of EOF, prints a newline, and exits

Constants: ---

Changing data: ---
*/

main ()
{
    int c;
    c = EOF;
    printf("%d\n", c);
}
