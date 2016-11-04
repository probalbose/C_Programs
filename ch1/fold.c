#include <stdio.h>

/* exercise 1-22
 *
 * fold: "folds" long input lines into 2 or more shorter lines after last 
 * non-blank char that occurs after 10th column of input. 
 *
 * Scenarios
 * - user provides input ending with EOF
 * - program prints output with line breaks ('\n' chars) inserted after last
 *   non-blank char occurring after 40th column 
 *
 *
 * Constants
 * - COL
 *   - column after which '\n' is inserted
 *
 * Changing Data
 * - c = getchar()
 * - i = position on line
 *
 * Main Function
 * - while (c = getchar()) != EOF
 *   - if (i < COL)
 *     - putchar(c)
 *     - ++i
 *   - else if (c == ' ' || c == '\t' || c == '\n')
 *     - putchar('\n')
 *     - putchar(c)
 *     - i = 1
 *   - else
 *     - putchar(c)
 *     - ++i
 */

#define COL 10

int main()
{
    int i, c;

    i = 1;
    while ((c = getchar()) != EOF)
    {
        if (i < COL)
        {
            putchar(c);
            ++i;
        }
        else if (c == ' ' || c == '\t' || c == '\n')
        {
            putchar('\n');
            i = 1;
        }
        else
        {
            putchar(c);
            ++i;
        }
    }
}




