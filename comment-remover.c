#include <stdio.h>

/* comment-remover: removes all lines from a C program & prints to stdout
 *
 * Scenarios
 * - user provides input in the form of a C program
 * - program prints the input C program without comments
 *
 * Constants
 *
 *
 * Changing Data
 * - c = getchar()
 * - int boundary = 0
 *   - if (c == '/')
 *     - boundary = 1
 *   - if (boundary == 1 && c == '/')
 *     - boundary = 0
 * - int incomment
 *   - 0 or 1
 *   - if 0: putchar(c)
 *   - if 1: continue;
 *     - if 
 *
 *
 * Main Function
 * - reads input char by char until EOF
 * - prints input with getchar() and putchar()
 * - if boundary of comment is detected, stop printing
 *   - int boundary, incomment
 *   - boundary -> switch between 0 and 1 when '/' is encountered
 *   - incomment -> switch between 0 and 1 when '*' is encountered && boundary == 1
 * - resume printing when boundary == 0 && incomment == 0
 *
 */

/* test comment...
 * continued...
 * end*/

int main()
{
    int c;
    int boundary = 0;
    int incomment = 0;

    while ((c = getchar()) != EOF)
    {
        /* entering comment... */
        if (c == '/' && incomment == 0)
            boundary = 1;
        else if (c == '*' && boundary == 1)
            incomment = 1;

        /* exiting comment... */
        else if (c == '/' && incomment == 1)
            boundary = 0;
        else if ((c != '/' && c != '*') && boundary == 0)
        {
            putchar(c);
            incomment = 0;
        }

        /* not in a comment */
        else if (incomment == 0)
        {
            putchar(c);
            boundary = 0;
        }
    }
}
