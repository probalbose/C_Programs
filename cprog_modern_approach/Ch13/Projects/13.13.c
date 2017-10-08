#include <stdio.h>

#define BUFSIZE 80

void encrypt(char *str, int shift);

int main(void) {
    char buf[BUFSIZE+1], ch, *p;
    int shift;

    // get input
    printf("enter a message to be encrypted: ");
    p = buf;
    while((ch = getchar()) != '\n' && (p - buf) < BUFSIZE)
        *p++ = ch;
    *p = '\0';

    // get shift
    printf("enter shift: ");
    scanf(" %d", &shift);

    // encrypt
    encrypt(buf, shift);

    // print result
    printf("encrypted message: %s\n", buf);

    return 0;
}

void encrypt(char *str, int shift) {
    char *p = str;
    for (; *p; p++) {
        // uppercase
        if (*p >= 'A' && *p <= 'Z')
            *p = ((*p - 'A') + shift) % 26 + 'A';
        // lowercase
        else if (*p >= 'a' && *p <= 'z')
            *p = ((*p - 'a') + shift) % 26 + 'a';
        else continue;
    }
}
