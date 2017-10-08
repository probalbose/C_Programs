/* modify itoa to handle the largest negative number supported
 * by the system it is run on
 *
 * Constants:
 * - 
 *
 *
 * Changing Data:
 * -
 *
 *
 * Outline:
 * - test if input is the greatest possible integer on system
 *   - use limits.h
 *   - if yes, do something
 *   - else, call itoa as normal
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAXELEMENT 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    char s[MAXELEMENT];
    int n = -485;

    if (n == -INT_MAX)
        printf("%d\n", -INT_MAX);
    else
    {
        itoa(n, s);
        printf("%s\n", s);
    }
    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;
    int test = 1;

    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /=10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
