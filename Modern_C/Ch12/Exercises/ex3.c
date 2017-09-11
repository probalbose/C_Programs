/*
 * reverses the elements of the array a
 */

#include <stdio.h>

#define N 10

int main(void) { 
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = &a[0], *q = &a[N-1], temp;

    while (p < q) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }

    printf("array:");
    for (temp = 0; temp < N; temp++)
        printf(" %d", a[temp]);
    printf("\n");
    return 0;
}
