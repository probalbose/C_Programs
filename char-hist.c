#include <stdio.h>

/* print histogram of lengths of words in input
 *
 * DOMAIN ANALYSIS
 * Scenarios
 * - User provides input; ends with EOF
 * - Program prints horizontal histogram like the one below:
 *   1 *
 *   2 **
 *   3 ****
 *   4 ***
 *   5 ******
 *   6 ****
 *   ...
 *
 *
 * Constants
 * - Maximum word length
 *   - 10
 *
 *
 * Changing Data
 * - c --> current character retrieved by getchar()
 * - Array containing the word-length frequencies
 * - Char-counter --> counts the # of chars in a word
 *   - at the end of a word, store current value in array and reset to 0
 *
 *
 * Main Function
 * - Enter while loop to read input
 * - Reads input char by char --> getchar()
 * - Begins counting at first non-whitespace character
 * - When the end of a word is encountered -- ' ', '\t', or '\n' -- find the length
 *   of that word in the array and increment it
 * - Reset the char-counter to 0 and resume counting at next non-whitespace char
 * - Once EOF is encountered, exit while loop --> while ((c = getchar) != EOF)
 * - Draw the histogram
 *   - iterate through values in array --> for loop
 *     - for (i = 0; i < MAXWORDLEN; ++i)...(access corresponding element in array)
 *   - print number of asterisks corresponding to the number at the ith index
 *     of the array
 *     - i.e. --> 3 *****
 *
 */

#define MAXWORDLEN 10

main ()
{
    int c, count, i, j;
    int lens[MAXWORDLEN + 1];

    for (i = 0; i <= MAXWORDLEN; ++i)
        lens[i] = 0;

    /* count chars in words...*/
    count = 0;
    while ((c = getchar()) != EOF)
    {
        if ((c != ' ' && c != '\n' && c != '\t') && (count < MAXWORDLEN))
            ++count;
        else if ((c == ' ' || c == '\n' || c == '\t') && (count > 0))
        {
            ++lens[count];
            count = 0;
        }
    }

    /* print histogram...*/
    for (i = 0; i <= MAXWORDLEN; ++i)
    {
        if (lens[i] >= 1)
        {
            printf("\n%d| ", i);
            for (j = 0; j < lens[i]; ++j)
                putchar('*');
        }
    }
    printf("\n");
}
