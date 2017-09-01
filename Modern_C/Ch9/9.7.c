#include <stdio.h>

int power(int x, int n);

int main(void) {
    int x, n;

    printf("enter an integer x and its power n: ");
    scanf(" %d %d", &x, &n);

    printf("%d to power of %d: %d\n", x, n, power(x, n));
    
    return 0;
}

int power(int x, int n) {
    // base case
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power(x, n/2) * power(x, n/2);
    else
        return x * power(x, n-1);
}
