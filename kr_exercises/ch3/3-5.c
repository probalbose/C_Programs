/* itob(n,s,b): converts integer n into a base b char representation in the
 * string s
 *
 * SUPPORTS BASES UP TO 16
 *
 * EXAMPLE: itob(n,s,16) -> formats n as a hex integer in s
 *
 * Constants:
 *
 * Changing Data:
 * - ints n, b
 *
 * Outline:
 * - main calls itob with n, s, b
 * - main then prints s
 *
 */

#include <stdio.h>
#include <string.h>

#define MAXELEMENT 1000

void itob(int n, char s[], int base);
void reverse(char s[]);

extern char bases[16];
char bases[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

int main(void)
{
    int n = 16; // 10 in hex; 20 in octal
    char s[MAXELEMENT];
    int b = 8;
    itob(n,s,b);
    printf("%s\n", s);
    return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign;

    if (b > 10)
        b;
    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {
        s[i++] = n % b + '0';
    } while ((n /= b) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j --)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
