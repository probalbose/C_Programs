#include <stdio.h>

/* replace multiple blanks with a single blank */

main ()
{
    int c, blanks;

    blanks = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' && blanks == 0)
        {
            blanks = 1;
            putchar(c);
        }
        if (c != ' ')
        {
            blanks = 0;
            putchar(c);
        }
    }
}
