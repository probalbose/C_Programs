#include <stdio.h>

/* print histogram of the frequencies of chars in input
 *
 * DOMAIN ANALYSIS
 * Scenarios
 * - user provides input; program accepts input until EOF is entered by user
 * - program prints histogram of asterisks showing the frequencies of the 
 *   characters present in user input
 *
 * Constants
 *
 *
 * Changing Data
 * - c, for getchar()
 * - array for tracking the char frequencies
 *   - freqs[128]
 *
 *
 * Main Function
 * - inspects input char by char --> use getchar()
 * - increments array element corresponding to each char inspected
 *   - i.e. ++freqs[c]
 * - draws histogram of the chars
 *   - i.e. 
 *     a | ***
 *     b | ****
 *     c | *****
 *     ...
 *
 *   - something like...
 *     putchar('i');
 *     printf(" | ");
 *     for (j = 0; j < freqs[i]; ++j)
 *         putchar('*');
 *     putchar('\n');
 */

main ()
{
    int c, i, j;
    int freqs[128];

    /* set all array values equal to 0 */
    for (i = 0; i < 128; ++i)
        freqs[i] = 0;

    /* count chars in input until EOF is encountered */
    while ((c = getchar()) != EOF)
    {
        ++freqs[c];
    }

    /* print histogram starting at ascii value for "!" */
    for (i = 33; i < 128; ++i)
    {
        putchar(i);
        printf(" | ");
        for (j = 0; j < freqs[i]; ++j)
            putchar('*');
        putchar('\n');
    }
}
