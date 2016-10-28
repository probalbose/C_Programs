#include <stdio.h>

/* replace tabs with appropriate number of spaces */

#define STOPWIDTH 8

int main ()
{
    int i, j, c;

    i = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            if (i < (STOPWIDTH + 1))
            {
                for (j = i; j < (STOPWIDTH + 1); ++j)
                {
                    putchar('#');
                }
                i = STOPWIDTH + 1;
            }
            else
            {
                for (j = 0; j < (STOPWIDTH - ((i-1) % STOPWIDTH)); ++j)
                    putchar('#');
                i = i + j;
            }
        }
        else if (c == '\n')
        {
            putchar(c);
            i = 1;
        }
        else
        {
            putchar(c);
            ++i;
        }
    }
    return 0;
}
