#include <stdio.h>

/* print one word per line
 *
 * DOMAIN ANALYSIS
 *
 * Scenarios
 * - user enters input; ends input with EOF
 * - program reads input character by character --> getchar()
 * - program prints newline at end of each word
 *   - detects tabs & spaces
 *
 * Constants
 * --
 *
 * Changing Data
 * - User input
 *   - use a variable, c, to represent current char being read by program
 *
 */

main ()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
            putchar('\n');
        else
            putchar(c);
    }
}
