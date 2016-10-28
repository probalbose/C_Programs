#include <stdio.h>

/* reverse a string and print the result
 *
 * DOMAIN ANALYSIS
 * Scenarios
 * - user enters input ending with EOF
 * - program reads each line of input and prints the line in reverse
 * - program exits when it encounters EOF
 *
 *
 * Constants
 * - MAXLINESIZE
 *
 *
 * Changing Data
 * - line of input
 *   - line[MAXLINESIZE]
 * - len
 *   - returned by getln()
 * - c in (c = getchar())
 * - i for iteration
 *
 *
 * Main Function Features
 * - reads a line of input by reading a line into an array
 *   - !!!
 *   - int getln(char line[], int MAXLINESIZE)
 *     - reads line of input into line[]
 *     - returns length of the line
 * - prints each char of the line in reverse (starts at the end of the line)
 *   - !!!
 *   - void rev(char to[], char from[])
 *   - uses len to set initial value of i in for loop for printing the chars
 *
 */

#define MAXLINESIZE 1000

int getln(char l[], int maxlinesize);
void rev(char to[], char from[], int length);

int main()
{
    int len, i;
    char line[MAXLINESIZE];
    char r[MAXLINESIZE];

    while ((len = getln(line, MAXLINESIZE)) > 0)
    {
        printf("Input: %s", line);
        rev(r, line, len);
        printf("Reversed: %s", r);
    }
    return 0;
}

int getln(char ln[], int lim)
{
   int i, c; 

   for (i = 0; ((i < (lim - 1)) && (c = getchar()) != EOF && c != '\n'); ++i)
        ln[i] = c;

   if (c == '\n')
   {
       ln[i] = c;
       ++i;
   }

   ln[i] = '\0';
   return i;
}

void rev(char to[], char from[], int l)
{
    int i;

    for (i = 0; i <= l - 2; ++i)
        to[i] = from[l-2-i];
    to[l-1] = '\n';
    to[l] = '\0';
}




