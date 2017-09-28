#include <stdio.h>

#define BUFSIZE 100

int strcmp(char *s, char *t);

int main(int argc, char *argv[]) {
    char *buf1 = "computer";
    char *buf2 = "computers";
    printf("%d\n", strcmp(buf1, buf2));

    return 0;
}

int strcmp(char *s, char *t) {
    while (*s++ == *t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
