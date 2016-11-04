#include <stdio.h>

/* entab: replace strings of blanks with the minimum number of tabs and blanks 
 * to achieve the same spacing. 
 *
 * Scenarios
 * - User provides input; ends with EOF
 * - program replaces strings of blanks w/ min. # of tabs & spaces to get same
 *   spacing
 * - program prints result with spaces replaced by '#' to show changes applied
 *   to input
 *
 * Constants
 * - MAXLINESIZE
 * - STOPWIDTH
 *
 * Changing Data
 * - c from c = getchar()
 * - i, index variable for iteration
 * - j, another index variable for iteration
 * - # of spaces in a string of consecutive blanks
 *   - int lenb
 * - # of tabs to insert instead of spaces
 *   - int numt
 * - # of blanks to insert after inserting tabs
 *   - int numb
 *
 * Main Function
 * - lenb = 0
 * - get input from user w/ while ((c = getchar()) != EOF)
 * - if (c == ' ')
 *   - ++lenb
 * - if ((c != ' ') && lenb > 0)
 *   - calculate numb and numt
 *     - print corresponding number of tabs and blanks w putchar()
 *   - lenb = 0 when done
 * - else
 *   - putchar(c)
 *
 *
 */

#define MAXLINESIZE 1000
#define STOPWIDTH 8

int gettabs(int lenblank, int pos); /* gets number of tabs to print */
int puttabs(int numtabs, int startindex); /* !!! prints numt '\t' chars and returns current index in line */

int main ()
{
    int c;
    int i, j;
    int tabbedi;
    int lenb = 0; /* number of consecutive blank spaces */
    int numt; /* number of tab chars to print */

    i = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++lenb;
        else if (c == '\n')
        {
            putchar(c);
            i = 1;
            lenb = 0;
        }
        else if (c != ' ' && lenb == 1)
        {
            putchar('#');
            putchar(c);
            lenb = 0;
        }
        else if (c != ' ' && lenb > 1)
        {
            numt = gettabs(lenb, i);

            /* DEBUG 
            printf("\nnumt: %i\n", numt);
            */

            /* put tabs */
            if (numt > 0)
                i = puttabs(numt, i);

            /* put blanks */
            for (j = 0; j < ((i + lenb) - i); ++j)
                putchar('#');

            putchar(c);
            i = i + lenb;
            lenb = 0;
        }
        else
        {
            putchar(c);
            ++i;
        }
    }
    return 0;
}

int gettabs(int numblanks, int index)
{
    int numt = 0;
    int end;

    end = index + numblanks;

    /* move index to next tab stop */

    while (((index % STOPWIDTH) + 1) != 1 && index < end)
        ++index;
    if (index < end)
        ++numt;

    /* find how many more tabs we can print */
    while ((index = index + STOPWIDTH) < end)
        ++numt;
    return numt;
}

/* puttabs: print num '\t' chars; return new index (position for c = getchar()) */
int puttabs(int numtabs, int start)
{
    int end = start;
    int i;

    for (i = 0; i < numtabs; ++i)
    {
        putchar('\t');
        end = end + STOPWIDTH;
    }
    return end;
}

