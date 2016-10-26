#include <stdio.h>

/* count blanks, tabs, and newlines */

/* DOMAIN ANALYSIS
 * Scenarios:
 * - Program takes input from user until EOF is encountered
 * - Program prints number of blanks, tabs, and newlines
 *
 * Constants:
 *
 *
 * Changing data:
 * # of blanks
 * # of tabs
 * # of newlines
 *
 * Main function:
 * count blanks, tabs, newlines while receiving input from user
 * print blanks, tabs, and newlines
 */

main ()
{
    int c, blanks, tabs, newlines;

    blanks = 0;
    tabs = 0;
    newlines = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++newlines;
    }
    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", blanks, tabs, newlines);
}
