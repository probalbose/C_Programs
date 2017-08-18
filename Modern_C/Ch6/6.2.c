#include <stdio.h>

int main(void) {
    // get 2 numbers
    // determine which one is greatest
    // set m = larger number, n = smaller number
    // Euclid's algorithm

    int m, n, tmp, remainder;
    printf("Enter 2 integers: ");
    scanf("%d %d", &m, &n);

    // make sure m is greater than n
    if (m < n) {
        tmp = m;
        m = n;
        n = tmp;
    }

    // Euclid's algorithm
    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    printf("Greatest common divisor: %d\n", m);

    return 0;
}
