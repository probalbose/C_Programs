#include <stdio.h>

#define NELEMS(a) ((sizeof (a)) / (sizeof(a[0])))

int main(void) {
    int arr[3];
    int arr2[12];
    printf("size of arr[3]: %ld\n", NELEMS(arr));
    printf("size of arr2[12]: %ld\n", NELEMS(arr2));
    return 0;
}
