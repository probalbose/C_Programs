#include <stdio.h>

/* copy input to output
 * replace tabs with \t
 * replace backspaces with \b
 * replace backslashes with \\
 *
 * DOMAIN ANALYSIS
 * Scenarios
 * - program accepts input from user until newline is entered
 * - program prints output with tabs, backspaces, and 
 *   backslashes excaped
 *
 * Constants
 * - EOF sequence
 *
 * Changing data
 * - input stream
 *   - represent each char with -> c = getchar()
*/

main ()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
            continue;
        }
        if (c == '\b')
        {
            putchar('\\');
            putchar('b');
            continue;
        }
        if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
            continue;
        }
        putchar(c);
    }

}
