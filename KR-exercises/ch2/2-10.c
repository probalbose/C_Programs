/* rewrite lower() so that it uses a conditional expression instead of if-else
 *
 * Constants
 * - test string
 *
 * Changing Data
 * - i for iteration
 * - c in putchar(c)
 *
 * Outline
 * - main() calls lower on each char of some string
 * - lower() reads a char
 *   - returns lowercase char if ('A' <= char <= 'Z')
 *   - else returns char
 *
 */

#include <stdio.h>
#define TESTSTRING "BLASH BLAH BLH! IOE:ALID{P"

int lower(char c);

int main(void)
{
    int i;
    char s[] = TESTSTRING;

    for (i=0; s[i] != '\0'; ++i)
        printf("%c", lower(s[i]));
    printf("\n");
    return 0;
}

int lower(char c)
{
    return c <= 'Z' && c >= 'A' ? (c + 'a' - 'A') : c;
}

