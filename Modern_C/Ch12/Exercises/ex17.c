#include <stdio.h>

#define N 3
#define LEN 3

int sum_two_dimensional_array(const int *a, int n);

int main(void) {
    const int arr[N][LEN] = {{1, 2, 3},
                             {3, 2, 1},
                             {1, 2, 3}};

    printf("sum of the array is: %d\n", sum_two_dimensional_array(arr[0], N));

    return 0;
}

int sum_two_dimensional_array(const int *a, int n) {
    const int *p;
    int sum = 0;

    for (p = a; p < a + n * LEN; p++)
        sum += *p;

    return sum;
}
