#include <stdio.h>

int main(void) {
    int count = 0, input, result, i;

    printf("Enter number of squares: ");
    scanf("%d", &input);

    getchar() == ' ';

    for (i = 1; i <= input ; i++) {
        if (count == 24) {
            printf("Press Enter to continue...");
            do {
            } while (getchar() != '\n');
            count = 0;
        }
        count++;
        printf("%d squared is %d\n", i, i*i);
    }
    return 0;
}
