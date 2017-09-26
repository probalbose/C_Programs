#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

void censor(char str[]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("program takes 1 string argument\n");
        return 1;
    }

    char buf[BUFSIZE] = {0};
    
    // get input
    strncpy(buf, argv[1], BUFSIZE);
    
    // censor it
    censor(buf);

    // print the result
    printf("censored string: %s\n", buf);

    return 0;
}

void censor(char str[]) {
    char *p = str;

    for (p = str; p < str + BUFSIZE && *p != '\0'; p++)
        if (*p == 'f' && *(p+1) == 'o' && *(p+2) == 'o')
            *p = *(p+1) = *(p+2) = 'x';
}
