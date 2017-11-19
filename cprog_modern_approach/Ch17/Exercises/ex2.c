#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char *str);

int main(void) {
    return 0;
}

char *duplicate(char *str) {
    char *p = malloc(strlen(str) + 1);
    if (p != NULL) 
        strcpy(p, str);
    return p;
}
