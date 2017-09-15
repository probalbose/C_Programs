#include <stdio.h>

void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main(void)
{
    int a[10] = {38, 4, 38, 84, 65, 9, 5, 14, 76, 49};
    int largest = 0, second_largest = 0, i;

    printf("Array contents: ");
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
        printf("\n");

    find_two_largest(a, sizeof(a) / sizeof(a[0]), &largest, &second_largest);
    printf("Largest: %d, Second Largest: %d\n", largest, second_largest);
    return 0;
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest) {
    const int *p;

    *largest = 0;
    *second_largest = 0;

    for (p = a; p < a + n; p++) {
        if (*p > *largest)
            *largest = *p;
    }

    for (p = a; p < a + n; p++) {
        if (*p > *second_largest && *p != *largest)
            *second_largest = *p;
    }
}
