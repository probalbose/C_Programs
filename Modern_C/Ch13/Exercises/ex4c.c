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
    
    // (c) Have it stop reading at the first newline character, and store it in the string
    for (i; i < n; i++) {
        ch = getchar();
        str[i] = ch;
        if (ch == '\n')
            break;
    }
    str[++i] = '\0';
    return i;
}
