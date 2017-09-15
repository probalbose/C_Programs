#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int temperatures[7][24] = {0};
    int row;

    srand((unsigned int) time(NULL));

    // populate temperature array
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 24; j++)
            temperatures[i][j] = rand() % 100;
    
    // ask user which row to print
    printf("which row would you like to print? (1-27): ");
    scanf(" %d", &row);
    row--;

    // print requested row
    printf("row %d: ", row+1);
    for (int *j = temperatures[row]; j < &temperatures[row][24]; j++)
        printf("%d ", *j);
    printf("\n");

    return 0;
}
