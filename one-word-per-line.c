#include <stdio.h>

/* copy input to output, printing one word per line
 *
 * DOMAIN ANALYSIS
 * Scenarios
 * - Program accepts input from user
 * - Program prints the input from the user, one word per line
 *
 * Constants
 * --
 *
 * Changing Data
 * - user input
 *
 * Main Function Features
 * - variable that represents current character, c
 *   - c = getchar()
 * - reads input until EOF is reached
 *   - while ((c = getchar()) != EOF)
 * - if c == ' ', print newline instead of space
 */

main ()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            putchar('\n');
        else
            putchar(c);
    }
}


