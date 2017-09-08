/*
 * num = numerator
 * den = denominator
 */

#include <stdio.h>

void reduce(int num, int den, int *reduced_num, int *reduced_den);

int main() {
    int num, den, m, n, tmp, reduced_num, reduced_den;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &den);

    reduce(num, den, &reduced_num, &reduced_den);

    printf("In lowest terms: %d/%d\n", reduced_num, reduced_den);
    
    return 0;
}

void reduce(int num, int den, int *reduced_num, int *reduced_den) {
    int m, n, tmp;

    // get gcd
    if (num > den) {
        m = num;
        n = den;
    }
    else {
        m = den;
        n = num;
    }

    do {
        tmp = m % n;
        m = n;
        n = tmp;
    } while (n > 0);

    // m is now the gcd
    *reduced_num = num / m;
    *reduced_den = den / m;
}
