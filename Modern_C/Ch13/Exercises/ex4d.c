#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 10

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
    
    // (d) Have it leave behind the characters it doesn't have room to store
    while (i < n) {
        ch = getchar();
        if (ch == '\n')
            break;
        else 
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
