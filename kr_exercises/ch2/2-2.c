#include <stdio.h>

/* rewrite the for loop:
 *   for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *
 * ...but don't use the logical operators && or ||
 */

int main()
{
    int c;
    int i = 0;
    int lim = 10;

    while (i < lim - 1)
    {
        if ((c = getchar()) == '\n')
            i = lim - 1;
        else if (c == EOF)
            i = lim - 1;
        else
        {
            putchar(c);
            ++i;
        }
    }
    putchar('\n');
    return 0;
}
