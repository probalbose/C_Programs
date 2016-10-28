#include <stdio.h>

/* count characters in input; version 2 */

main ()
{
    double nc;

    for (nc=0; getchar() != EOF; ++nc)
        ;
    /* .0 in the conversion spec %.0f suppresses printing of
     * the decimal point and fraction part, which is 0. */
    printf("%.0f\n", nc);
}
