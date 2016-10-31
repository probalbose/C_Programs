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
 * - 
 *
 */

/* test comment...
 * continued...
 * end*/

int main()
{
    int c;
    int boundary = incomment = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '/')
            boundary = 1;

        else if (incomment == 0)
            putchar(c);
    }
}
