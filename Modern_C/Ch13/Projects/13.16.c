#include <stdio.h>
#include <string.h>

#define SIZE 100

void reverse(char *msg);

int main(void) {
    char arr[SIZE] = {0}, *p;
    
    printf("enter a message: ");
    for (p = arr; p < arr + SIZE; p++) {
        *p = getchar();
        if (*p == '\n') {
            *p = '\0';
            break;
        }
    }

    reverse(arr);

    printf("reversal is: %s\n", arr);
    
    return 0;
}

void reverse(char *msg) {
    char *p, *q, tmp;
    p = msg;
    q = msg + strlen(msg) - 1; // avoid '\0' at end of msg
    for (; p < q; p++, q--) {
        tmp = *p;
        *p = *q;
        *q = tmp;
    }
}
