#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

void capitalize(char str[], int len);

int main(int argc, char *argv[]) {
    char str[BUFSIZE] = {0};

    if (argc != 2) {
        printf("program takes 1 parameter, a string\n");
        return 1;
    }

    strncpy(str, argv[1], BUFSIZE);

    capitalize(str, BUFSIZE);

    printf("%s\n", str);

    return 0;
}

void capitalize(char str[], int len) {
    char *p;

    for (p = str; p < str + len; p++)
        *p = toupper(*p);
}
