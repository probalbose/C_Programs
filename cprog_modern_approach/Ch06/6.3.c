#include <stdio.h>

int main() {
    int num, den, m, n, tmp, new_num, new_den;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &den);

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
    new_num = num / m;
    new_den = den / m;

    printf("In lowest terms: %d/%d\n", new_num, new_den);
    
    return 0;
}
