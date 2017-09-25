#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int read_line(char str[], int n);

int main(void) {
    char buf[BUFSIZE];
    printf("enter a line: ");
    read_line(buf, BUFSIZE);
    printf("you entered: %s\n", buf);
    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    
    // (b) Have it stop reading at the first whitespace character
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (isspace(ch))
            break;
        else if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
