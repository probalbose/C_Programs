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
 * first, find out if adding one tab is ok
 * !!!
 * if there are even more spaces after adding first tab, then...
 * while ((i + STOPWIDTH) < (i + lenb))...!!!
 * - fix this ^^^
 */

#define MAXLINESIZE 1000
#define STOPWIDTH 8

int entab(int lenblank, int pos);

int main ()
{
    int c;
    int i;
    int lenb = 0;
    int numt;

    i = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++lenb;
        else if (c == '\n')
            i = 1;
            lenb = 0;
        else if (c != ' ' && lenb > 0)
        {
            numt = entab(lenb, i);
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

int entab(int numblanks, int index)
{
    int j;

    if (index <= STOPWIDTH)
        return 0;
    else
    {
        /* do something */;
    }
}







