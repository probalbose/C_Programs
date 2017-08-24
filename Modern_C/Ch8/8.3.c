#include <stdio.h>

int main(void) {
    int digit_seen[10] = {0}, digit, i;
    long n;

    for (;;) {
        printf("Enter a number (0 or less to quit): ");
        scanf("%ld", &n);

        if (n <= 0) {
            printf("Exiting...\n");
            break;
        }

        while (n > 0) {
            digit = n % 10;
            digit_seen[digit]++;
            n /= 10;
        }

        printf("Digits:      ");
        for (i = 0; i < 10; i++)
            printf("%d ", i);
        printf("\n");

        printf("Occurrences: ");
        for (i = 0; i < 10; i++)
            printf("%d ", digit_seen[i]);
        printf("\n");

        // 0 out digit_seen
        for (i = 0; i < 10; i++)
            digit_seen[i] = 0;
    }

    return 0;
}

