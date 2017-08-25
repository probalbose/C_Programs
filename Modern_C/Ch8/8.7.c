/*
 * Read in 5 rows of 5 integers
 * Print the sum of each row
 * Print the sum of each column
 */

#include <stdio.h>

int main(void) {
    char input;
    int matrix[5][5];
    int row1 = 0, row2 = 0, row3 = 0, row4 = 0, row5 = 0; //sums
    int col1 = 0, col2 = 0, col3 = 0, col4 = 0, col5 = 0; //sums
    int i, j; //for iteration

    // fill matrix
    for (i = 0; i < 5; i++) {
        printf("enter row %d: ", i+1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // print matrix
    for (i = 0; i < 5; i++) {
        printf("row %d:", i);
        for (j = 0; j < 5; j++)
            printf(" %d", matrix[i][j]);
        printf("\n");
    }

    printf("\n");

    return 0;
}
