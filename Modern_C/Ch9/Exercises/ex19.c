#include <stdio.h>

void pb(int n);

int main(void) {
    int n;
    printf("enter a number n: ");
    scanf("%d", &n);
    pb(n);
    return 0;
}

void pb(int n) {
    if (n != 0) {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}
