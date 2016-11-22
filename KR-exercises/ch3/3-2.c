/* escape(s,t): converts chars like newline and tab into visible escape sequences
 * as it copies string t to s
 * - uses a switch
 *
 * unescape(s,t): does the opposite of escape(); converts visible escape sequences
 * into corresponding chars
 *
 *
 *
 *
 */

#include <stdio.h>

#define MAXELEMENT 2000

void escape(char to[], char from[]);
void unescape(char to[], char from[]);

int main(void)
{
    char s[MAXELEMENT];
    char t[MAXELEMENT];
    char u[MAXELEMENT];
    int i;

    // construct string t
    for (i = 0; i < 26; ++i)
    {
        switch (i) 
        {
            case 13:
                t[i] = '\t';
                break;
            case 20:
                t[i] = '\n';
                break;
            default:
                t[i] = ('A' + i);
                break;
        }
    }
    t[i++] = '\n';
    t[i] = '\0';

    // escape(s,t)
    printf("t: %s", t);
    escape(s,t);
    printf("s: %s", s);

    // unescape(u,s)
    unescape(u,s);
    printf("u: %s", u);

    return 0;
}

void escape(char to[], char from[])
{
    int i;
    int j = 0;

    for (i = 0; from[i] != '\0'; ++i)
    {
        switch (from[i]) {
            case '\n': 
                // put backslash char at current index & put n at next index
                to[j++] = '\\';
                to[j] = 'n';
                break;
            case '\t':
                // put backslash car at current index & put t at next index
                to[j++] = '\\';
                to[j] = 't';
                break;
            default:
                to[j] = from[i];
                break;
        }
        ++j;
    }
    to[j++] = '\n';
    to[j] = '\0';
}

void unescape(char to[], char from[])
{
    int i;
    int j = 0;

    for (i = 0; from[i] != '\0'; ++i)
    {
        switch (from[i])
        {
            case '\\':
                switch (from[i+1])
                {
                    case 'n':
                        to[j] = '\n';
                        break;
                    case 't':
                        to[j] = '\t';
                        break;
                }
                ++i;
                break;
            default:
                to[j] = from[i];
                break;
        }
        ++j;
    }
    from[j] = '\0';
}

