#include <stdio.h>
#include <stdlib.h>

int cmp(const void *, const void *);

int main(void) {
    int arr[100] = {0};
    qsort(&arr[50], 50, sizeof(arr[50]), cmp); 
    return 0;
}

int cmp(const void *p, const void *q) {
    const int *p1 = (const int *) p;
    const int *q1 = (const int *) q;
    return *p1 - *q1;
}
