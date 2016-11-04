#include <stdio.h>

/* print only lines that are longer than 80 chars 
 *
 * DOMAIN ANALYSIS
 * Scenarios
 * - user provides input, finishes with EOF
 * - program processes each line; prints length of current line; 
 *   - prints line if length > 80 chars
 * - program exits
 *
 * Constants
 * - MINSIZE
 *   - 80 chars
 * - MAXSIZE
 *   - 1000 chars
 *
 * Changing Data
 * - line length
 * - array to hold valid lines ( > 80 chars) for printing
 *   - line[1000]
 *
 * Main Function Features
 * - reads input --> getln(line, MAXSIZE)
 *   - !!! (main() should call this function)
 *   - returns length of current line of input
 *   - see C Programming section 1.9, "Character Arrays"
 * - if current line > 80 chars, stores line in array and prints them
 *   - copy(to[], from[]) 
 *     - !!! (main() should call this function)
 *     - stores the line in a safe place; see C Programming section 1.9, "Character Arrays"
 *   - for (i = 0; i < len = getln(line, MAXSIZE)
 *
 * */

#define MINSIZE 80
#define MAXSIZE 1000

int getln(char line[], int maxsize);

main ()
{
    int len;            /* length of current line */
    char line[MAXSIZE]; /* current input line */

    while ((len = getln(line, MAXSIZE)) > 0)
    {
        printf("Line length: %d\n", len);
        if (len > MINSIZE)
            printf("%s\n", line);
    }
}

/* getln: read a line into s, return length */
int getln(char s[], int lim)
{
    int c, i;

    for (i=0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}










