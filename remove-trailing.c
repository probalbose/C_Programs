#include <stdio.h>

/* remove trailing blanks and tabs from each line of input; delete entirely blank lines
 *
 * DOMAIN ANALYSIS
 * Scenarios
 * - User provides input; ends input with EOF
 * - Program reads input one line at a time, deleting trailing blanks and tabs from each line of input
 *   - Program also deletes (i.e. ignores) entirely blank lines
 *
 *
 * Constants
 * - MAXLINESIZE
 *
 *
 * Changing Data
 * - line of input
 *   - load into an array, line[] 
 * - char counter in getln()
 *   - during each iteration, increment if whitespace == 0
 * - whitespace
 *   - variable in getln()
 *   - interp. whether program is reading consecutive whitespace chars
 * - i, for iterating through line[]
 *
 * Main Function Features
 * - getln()
 *   - call getln() to get current line of input
 *   - returns length of the line
 *   - reads line into char array
 *   - set whitespace to 1 at beginning of line
 *   - set whitespace to 1 when c holds either ' ' or '\t'
 *     - read the whitespace char into line, THEN set whitespace to 1
 *   - set whitespace to 0 when c holds an alphanumeric char
 *   - if (whitespace == 1 && (c == ' ' || c == '\t'))
 *     - do not read char into line or increment char counter, c
 *   - once all chars have been read, add a '\0' onto the end of line[]
 *   - if EOF is only input, return 0
 * 
 * - prints the chars in line --> putchar()
 *   - if (len == 1 && line[i] == '\n')
 *     continue;  (***ie ignore the blank line)
 *   - else
 *          putchar(line[i]);
 *
 */

#define MAXLINESIZE 1000
int getln(char line[], int maxlinesize);

int main ()
{
    int len;
    char line[MAXLINESIZE];

    while ((len = getln(line, MAXLINESIZE)) > 0)
    {
        /* print line, ignoring blank lines */
        if (len > 1)
            printf("%s\n", line);
    }
    return 0;
}

int getln(char l[], int lim)
{
    int i, c, whitespace;

    whitespace = 1;
    i = 0;
    while (i < (lim - 1) && ((c = getchar()) != EOF) && c != '\n')
    {
        if (c == ' ' || c == '\t')
        {
            if (whitespace == 0)
            {
                whitespace = 1;
                l[i] = c;
                ++i;
            }
        }
        else if (whitespace == 0)
        {
            l[i] = c;
            ++i;
        }
        else if (whitespace == 1 && c != ' ' && c != '\t')
        {
            whitespace = 0;
            l[i] = c;
            ++i;
        }
    }
    if (c == '\n')
    {
        l[i] = c;
        ++i;
    }
    l[i] = '\0';
    return i;
}




