#include <stdio.h>

int gcd(int m, int n);

int main(void) {
    int m, n;
    printf("enter 2 integers m and n separated by spaces: ");
    scanf("%d %d", &m, &n);

    printf("greatest common divisor: %d\n", gcd(m, n));
    return 0;
}

int gcd(int m, int n) {
    if (m == 0)
        return n;
    else if (n == 0)
        return m;
    else {
        if (m >= n)
            return gcd(n, m % n);
        else
            return gcd(m, n % m);
    }
}
