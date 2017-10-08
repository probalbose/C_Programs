/* expand(s1,s2): expands shortand notations like a-z in s1 into abc...xyz
 * in s2
 *
 * Examples
 *
 * Constants
 * - max len of char array
 *
 * Changing Data
 * - char s1[]
 * - char s2[]
 *
 * Outline
 * - main() passes s1 and s2 to expand
 *   - s1 is some string
 *   - s2 is blank
 * - main prints s1 and then s2
 *
 * - expand(s1,s2)
 *   !!!
 *   Examples
 *   expand("a-zbc",s2) -> s2 = "abc...xyzbc"
 *   - step through array, checking current AND next char at each step
 *     - if next char is '-'
 *       - check the char after '-'
 *         - if the three chars correspond to a shorthand like a-z,A-Z,
 *           or 0-9, print all chars in the set
 *           - can be partial sets like a-e or 0-7
 *         - else just copy char from s1 to s2
 *     - else copy char from s1 to s2
 *
 */

#include <stdio.h>
#include <string.h>
#define MAXELEMENT 1000

void expand(char string1[], char string2[]);

int main(void)
{
    char s1[MAXELEMENT] = "some a-m text n-z yeahA-Z0-5-e";
    char s2[MAXELEMENT];
    expand(s1,s2);
    printf("%s", s2);
    return 0;
}

// String String -> Void
// copy s1 to s2, expanding shorthand notations like a-z and 0-9
void expand(char s1[], char s2[])
{
    int i, j, k;
    int len = strlen(s1);

    for (i = 0; i < len; ++i)
    {
        if (s1[i+1] == '-')
        {
            // lowercase letters 
            if ('a' <= s1[i] <= s1[i+2] <= 'z')
            {
                for (k = 0; k <= (s1[i+2] - s1[i]); k++, j++)
                    s2[j] = s1[i] + k;
                i += 2;
            }
            // uppercase letters 
            else if ('A' <= s1[i] <= s1[i+2] <= 'Z')
            {
                for (k = 0; k <= (s1[i+2] - s1[i]); k++, j++)
                    s2[j] = s1[i] + k;
                i += 2;
            }
            // numbers 
            else if ('0' <= s1[i] <= s1[i+2] <= '9')
            {
                for (k = 0; k <= (s1[i+2] - s1[i]); k++, j++)
                    s2[j] = s1[i] + k;
                i += 2;
            }
            // no shorthand matched
            else
                s2[j++] = s1[i];
        }
        else
            s2[j++] = s1[i];
    }
    s2[j++] = '\n';
    s2[j] = '\0';
}

