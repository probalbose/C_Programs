#include <stdio.h>

#define SIZE 100

int main(void) {
    char arr[SIZE] = {0}, *p;
    
    printf("enter a message: ");
    for (p = arr; p < arr + SIZE; p++) {
        *p = getchar();
        if (*p == '\n')
            break;
    }

    printf("reversal is: ");
    p--;
    for(; p >= arr; p--)
        printf("%c", *p);

    printf("\n");

    return 0;
}
