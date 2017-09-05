#include <stdio.h>

#define ARRAY_SIZE ((int) (sizeof(a) / sizeof(a[0])))

int main(void) {
    const int N = 10;
    int a[N], i;

    printf("enter %d numbers: ", N);
    for (i = 0; i < ARRAY_SIZE; i++)
        scanf("%d", &a[i]);
    
    printf("in reverse order:");
    for (i = ARRAY_SIZE - 1; i >= 0; i--)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
