#include <stdio.h>
#include <string.h>

#define BUFSIZE 20

int main(void) {
    char input [BUFSIZE+1] = {0};
    char largest[BUFSIZE+1] = {0};
    char smallest[BUFSIZE+1] = {0};

    // get first word
    printf("enter word: ");
    scanf("%s", input);
    strcpy(largest, input);
    strcpy(smallest, input);

    // start read loop
    for (;;) {
        printf("enter word: ");
        scanf("%s", input);
        // check for exit condition - four letter word
        if (strlen(input) == 4) break;
        // check against smallest
        if (strlen(input) <= strlen(smallest))
            strcpy(smallest, input);
        // check against largest
        else if (strlen(input) >= strlen(largest))
            strcpy(largest, input);
    }
    // print result
    printf("largest: %s\n", largest);
    printf("smallest: %s\n", smallest);
    return 0;
}
