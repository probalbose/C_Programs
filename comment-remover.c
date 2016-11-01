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
 * - int lastchar
 *   - previous character returned by getchar()
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
    int c, lastchar;
    int incomment = 0;
    int buf = 0; /* flag for handling funny sequences like /' */

    lastchar = 0;
    while ((c = getchar()) != EOF)
    {
        /* determine if program is currently reading a comment */
        /* entering a comment */
        if (lastchar == '/' && c == '*')
            incomment = 1;
        /* leaving a comment */
        else if (lastchar == '*' && c == '/')
        {
            incomment = 0;
            buf = 1;
        }

        /* print '/' and '*' chars that do not demarcate comments */
        else if (lastchar == '/' && c != '*' && buf == 0 && incomment == 0)
        {
            putchar(lastchar);
            putchar(c);
        }
        else if (lastchar == '*' && c != '/' && incomment == 0)
        {
            putchar(lastchar);
            putchar(c);
        }

        /* putchar if program is not reading a comment */
        else if (incomment == 0 && c!='/' && c!='*')
        {
            putchar(c);
            buf = 0;
        }
        lastchar = c;
    }
}
