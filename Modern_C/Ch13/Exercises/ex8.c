// answer is "tired-or-wired?"

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

int main(int argc, char *argv[]) {
    char str[BUFSIZE] = {0};

    strcpy(str, "tire-bouchon");
    strcpy(&str[4], "d-or-wi");
    strcat(str, "red?");

    printf("%s\n", str);

    return 0;
}
