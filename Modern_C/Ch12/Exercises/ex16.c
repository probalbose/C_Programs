#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_largest(int *a, int n);

int main(void) {
    int temperatures[7][24] = {0};
    int row;

    srand((unsigned int) time(NULL));

    // populate temperature array
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 24; j++)
            temperatures[i][j] = rand() % 100;
    
    for (int i = 0; i < 7; i++)
        printf("day %d highest temp: %d\n", i+1, find_largest(temperatures[i], 24));

    return 0;
}

int find_largest(int *a, int n) {
    int *p, *max;
    max = a;
    for (p = a; p < a + n; p++)
        if (*p > *max)
            max = p;
    return *max;
}
