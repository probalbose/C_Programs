/*
 * Read in 5 rows of 5 integers
 * Print the sum of each row
 * Print the sum of each column
 */

#include <stdio.h>

int main(void) {
    char input;
    const int matrix[5][5];
    int row_sum, col_sum, i, j;

    // fill matrix
    for (i = 0; i < 5; i++) {
        printf("enter row %d: ", i+1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n");

    // sum each row
    printf("row sums:");
    for (i = 0; i < 5; i++) {
        row_sum = 0;
        for (j = 0; j < 5; j++)
            row_sum += matrix[i][j];
        printf(" %d", row_sum);
    }

    // sum each column
    printf("\ncolumn sums:");
    for (i = 0; i < 5; i++) {
        col_sum = 0;
        for (j = 0; j < 5; j++)
            col_sum += matrix[j][i];
        printf(" %d", col_sum);
    }

    printf("\n");

    return 0;
}
