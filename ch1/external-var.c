#include <stdio.h>

/* external-var.c: use external variables to store and print the
 * longest line of input
 */

#define MAXLINE 1000    /* maximum input line size */

int max;                /* maximum length seen so far */
char line[MAXLINE];     /* current input line */
char longest[MAXLINE];  /* longest line saved here */

int getln(void);
void copy(void);

/* print longest input line; specialized version */
int main ()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getln()) > 0)
    {
        if (len > max)
        {
            max = len;
            copy();
        }
    }
    
    if (max > 0) 
        printf("Longest line: %s", longest);
    return 0;
}

/* getln: specialized version */
int getln(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: specialized version */
void copy(void)
{
    int i;
    extern char line[];
    extern char longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}






