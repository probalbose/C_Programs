#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void) {
    int a[10], n=10, biggest, second_biggest, i;

    printf("enter 10 integers: ");
    for (i = 0; i < 10; i++)
        scanf(" %d", &a[i]);

    find_two_largest(a, n, &biggest, &second_biggest);
    printf("biggest: %d\n", biggest);
    printf("second biggest: %d\n", second_biggest);

    return 0;
}
void find_two_largest(int a[], int n, int *largest, int *second_largest) {
    int i;

    *largest = *second_largest = 0;

    for (i = 0; i < n; i++) {
        if (a[i] > *largest)
            *largest = a[i];
    }

    for (i = 0; i < n; i++) {
        if (a[i] != *largest && a[i] > *second_largest)
            *second_largest = a[i];
    }
}
