/* any(s1,s2): returns first location in string s1 where any char
 * from string s2 occurs, or -1 if s1 contains no chars from s2.
 *
 * Scenarios
 * - processes 2 strings
 * - prints index (an integer) of the first occurrence of char in s1
 *
 * Constants
 * - s1, s2
 *
 * Changing Data
 * - i, j for iteration
 *
 * Outline
 * - initialize 2 strings
 * - main() calls any()
 *   - !!!
 * - main() prints return value of any()
 *   - an int
 *
 */


#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    char test1[] = "testing";
    char match1[] = "b";
    char test2[] = "testing";
    char match2[] = "hi";

    printf("finding match between '%s' & '%s'\n", test1, match1);
    printf("%d\n", any(test1, match1));
    printf("finding match between '%s' & '%s'\n", test2, match2);
    printf("%d\n", any(test2, match2));
    return 0;
}

/* any: return first index of string s1 that contains a char from
 * string s2, returns -1 if no chars match
 */

int any(char str1[], char str2[])
{
    int i;
    int j;
    int found = -2;

    for (i = 0; found < 1 && str1[i] != '\0'; ++i)
    {
        /* !!! */
        j = 0;
        while (str2[j] != '\0')
        {
            if (str1[i] == str2[j])
                found = i;
            ++j;
        }

    }
    return found + 1;
}
