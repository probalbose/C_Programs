#include <stdio.h>

/* 
 * Copy input to output, replacing multiple consecutives blanks 
 * with a single blank
*/

/*
 * DOMAIN ANALYSIS
 * Scenarios
 * - Program accepts input from user until EOF is encountered
 * - Program replaces consecutive blank chars with single blank chars
 * - Program prints the edited string after each newline entered by user
 *
 * Constants
 * - EOF
 *
 * Changing data
 * - user input
 *
 * Main function
 * - reads input from user
 * - when newline is entered: replace consecutive blank chars with single blank char
 * - print result 
 * - proceed until EOF is entered by user
*/

main ()
{
    int c, blanks;

    blanks = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' && blanks == 0)
        {
            blanks = 1;
            putchar(c);
        }    
        if (c != ' ')
        {
            blanks = 0;
            putchar(c);
        }
    }
}
