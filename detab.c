#include <stdio.h>

/* replace tabs in input with proper number of blanks to space
 * to the next tab stop. Assumes a fixed set of tab stops every
 * n columns. 
 *
 * DOMAIN ANALYSIS
 * Scenarios
 * - user provides some input; ends with EOF
 * - program scans each line for '\t' chars
 *   - replaces each '\t' with appropriate number of spaces to 
 *     reach next tab stop
 * - program prints the result; should look identical to user input
 *
 * Constants
 * - MAXLINESIZE
 * - STOPWIDTH, the number of spaces between tab stops (4)
 * - char STOPS[MAXLINESIZE], the columns at which tab stops occur
 *
 *
 * Changing Data
 * - current line length; retrieved by getln() 
 * - line[], char array representing current line
 * - c, the current char while reading a line; retrieved by getchar()
 * - the distance between c and the next tab stop
 *   - i.e. the number of spaces to the next tab stop
 * - the detabbed array that is printed by the program
 *
 * Main Function
 * - gets input from user with getln()
 *   - reads line of input into array char line[MAXLINESIZE]
 *   - returns length of the array
 *   - uses getchar()
 *
 * - sends char line[MAXLINESIZE] to a detabbing function
 *   - !!!
 *   - replace tabs with appropriate # of spaces
 *   - reads chars into char toprint[] until '\t' is encountered
 *     - when '\t' is read: 
 *       - if i < STOPWIDTH:
 *         - read (5 - i) spaces into toprint[]
 *       - else:
 *         - read ((i % STOPWIDTH) + 1) spaces into toprint[]
 *       - increment i for each ' ' added
 *     - continue assigning toprint[i] = line[i]
 *
 * - printf("%s\n", toprint)
 *
 */

#define MAXLINESIZE 1000
#define STOPWIDTH 4

int getln(char line[], int maxlinesize);
void detab(char toprint[], char from[]);

int main ()
{
    int len;
    char line[MAXLINESIZE];
    char toprint[MAXLINESIZE];

    while ((len = getln(line, MAXLINESIZE)) > 0)
    {
        /*
        detab(toprint, line);
        printf("%s", toprint);
        */
        printf("%s", line);
    }

    return 0;
}

/* getln: read line of input into s[]; return length of s[] */
int getln(char s[], int lim)
{
    int i, c;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* detab: replace '\t' chars with appropriate number of spaces */
void detab(char to[], char from[])
{
    /* !!! */
}




