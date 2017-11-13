#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
#define BUFSIZE 99

int main(void) {
    char s[BUFSIZE];
    int i;

    // (a) -> 'D' is the output
    // When TOUPPER is expanded, s[++i] occurs multiple times
    strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i]));
    putchar('\n');

    // (b) -> '2'
    // When TOUPPER is expanded, s[++i] occurs multiple times
    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));
    putchar('\n');

    return 0;
}
