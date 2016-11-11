/* squeeze(s1, s2): deletes each character in 
 * s1 that matches any character in the string s2
 *
 * Scenarios
 * - program removes chars of const char s2[] from
 *   char s1[]
 * - program prints new s1
 *
 * Constants
 * - const char s2[]
 *   - array which holds letters to be removed
 *
 * Changing Data
 * - i, j for iteration
 * - char s1[]
 * - int match
 *   - 0
 *   - set to 1 if s1[i] == s2[j]
 *
 * Main Function
 * - calls squeeze(s1, s2)
 *   - !!!
 *   - void squeeze(char s1[], const char s2[])
 *   - while s1[i] != '\0' && match == 0
 *     - for each s1[i], iterate thru s2 and
 *       compare values
 *       - while s2[j] != '\0'
 *       - if (s1[i] == s2[j]) --> match=1
 *       - ++j
 * - prints new s1
 *
 */
#include <stdio.h>
#include <string.h>

void squeeze(char s1[], const char s2[], char newstr[]);

int main ()
{
    int i, j;
    char str1[9] = "manifold";
    const char str2[5] = "anif";
    char new[1000];

    squeeze(str1, str2, new);
    printf("%s\n", new);
    return 0;
}

void squeeze (char string1[], const char string2[], char newstring[])
{
    int i, j, k,  match;

    i = j = k = 0;
    while (string1[i] != '\0')
    {
        match = 0;

        /* check current char of string1 for matches in string2 */
        for (j = 0; string2[j] != '\0' && match == 0; ++j)
        {
            if (string1[i] == string2[j])
                match = 1;
        }

        /* if no match was found... !!! */
        if (!match)
            newstring[k++] = string1[i];
        ++i;
    }
    newstring[k] = '\0';
}
