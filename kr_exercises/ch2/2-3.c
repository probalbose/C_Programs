/* 2-2: write htoi(s), which converts a string of hex digits into the 
 * equivalent integer value.
 *
 * Scenarios:
 * - input is hardcoded into program
 * - program prints converted output
 *
 * Constants:
 * - enums for hex values of upper and lowercase A-F
 * - test strings
 *   - "0xff"
 *     - htoi("0xff") should return 255
 *   - "gf2"
 *     - htoi("gf2") should return an error message
 *
 * Changing Data:
 * - i for iteration
 * - s[i]
 *   - current char inspected during main logic loop of htoi()
 *
 * Main Function:
 * - send 2 strings to int htoi(char s[])
 *   - !!!
 *   - initialize a variable to track the sum of the hex values
 *   - iterate thru string & add s[i] to total sum
 *   - if ( isxdigit(s[i]))
 *     - do a thing
 *   - else
 *     - print an error message
 * - print result
 */

#include <stdio.h>
#include <ctype.h>

#define TEST1 "ff" /* 255 */
#define TEST2 "ge2" /* invalid input */
#define TEST3 "0xf3" /* 243 */

int htoi(const char s[]);

int main ()
{
    printf("%d\n", htoi(TEST1));
    printf("%d\n", htoi(TEST2));
    printf("%d\n", htoi(TEST3));
    return 0;
}

int htoi(const char str[])
{
    int n = 0; /* hex chars */
    int i;
    int invalid_char = 0; /* flag for printing error for invalid input */

    /* catch optional leading "0x" or "0X" */
    if (str[0] == '0' && (str[1] == 'X' || str[1] == 'x'))
        i = 2;
    else
        i = 0;

    while (str[i] != '\0')
    {
        /* calculate decimal value of hex input */
        /* digit is one of 0-9 */
        if (isdigit(str[i]))
            n = 16 * n + (str[i] - '0');

        /* digit is one of a-f */
        else if (isxdigit(str[i]))      
            n = 16 * n + (10 + (toupper(str[i]) - 'A'));

        else
        {
            printf("invalid char detected: %c\n", str[i]);
            invalid_char = 1;
        }
        ++i;
    }
    if (!invalid_char)
        return n;
    else
        return 0;
}
