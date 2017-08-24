#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool digit_seen[10] = {false};
    int digit, i;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    printf("Repeated digits: ");

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit])
            printf("%d ", digit);
        digit_seen[digit] = true;
        n /= 10;
    }

    printf("\n");

    return 0;
}

