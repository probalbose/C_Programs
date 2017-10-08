#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

void remove_filename(char *url);

int main(int argc, char *argv[]) {
    char url[BUFSIZE];

    strcpy(url, argv[1]);

    remove_filename(url);

    printf("base url: %s\n", url);

    return 0;
}

void remove_filename(char *url) {
    // find last forward slash
    while (*url++)
        ;
    while (*url-- != '/')
        ;

    // replace it with null byte
    *++url = '\0';
}
