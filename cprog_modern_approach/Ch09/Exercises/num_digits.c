#include <stdio.h>

int num_digits(int n);

int main(void) {
    int n;
    printf("enter an integer n: ");
    scanf("%d", &n);
    printf("number of digits: %d\n", num_digits(n));
    return 0;
}

int num_digits(int n) {
    int count = 0;
    do {
        n /= 10;
        count++;
    } while (n > 0);
    return count;
}
