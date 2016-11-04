#include <stdio.h>
/* syntax-checker: check for rudimentary syntax errors in C programs, i.e.
 * unclosed brackets & parentheses as well as missing semicolons before '\n' chars
 *
 * Scenarios
 * - user provides input in the form of a C program
 * - syntax-checker reads each line of program and counts '(', '{' chars
 *   - prints input program
 *   - prints counts of unclosed parentheses & brackets at the end of output
 *
 * Constants
 * - MAXLINESIZE
 *
 *
 * Changing Data
 * - c = getchar()
 * - char line[MAXLINESIZE]
 * - len
 *   - length of line[]
 * - i for iteration
 * - parencount
 *   - count of unclosed '('
 *   - ++ when c == '('
 *   - -- when c == ')'
 * - bracketcount
 *   - count of unclosed '{'
 *   - ++ when c == '{'
 *   - -- when c == '}'
 *
 * Main Function
 * - gets current line with getln()
 *   - !!!
 * - iterates through array returned by getln()
 * - increments parencount or bracketcount when c == '(' or c == '{'
 * - decrements parencount or bracketcount when c == ')' or c == '}'
 * - prints the line
 * - once EOF is reached, i.e. len = getln() = 0...
 *   - print values of parencount & bracketcount
 *
 *
 */

#define MAXLINESIZE 1000

int getln(char line[], int limit);

int main ()
{
    int parencount = 0;
    int bracketcount = 0;
    int i, len;
    char line[MAXLINESIZE];
    while ((len = getln(line, MAXLINESIZE)) > 0)
    {
        for (i = 0; i <= len; ++i)
        {
            if (line[i] == '(')
                ++parencount;
            else if (line[i] == ')' && parencount > 0)
                --parencount;
            else if (line[i] == '{')
                ++bracketcount;
            else if (line[i] == '}' && bracketcount > 0)
                --bracketcount;
            putchar(line[i]);
        }
    }
    printf("Unclosed parentheses: %d\n", parencount);
    printf("Unclosed brackets: %d\n", bracketcount);
    return 0;
}

int getln(char line[], int lim)
{
    int c, i;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
/* test parenthesis and bracket detection */
/* (({{})*/
