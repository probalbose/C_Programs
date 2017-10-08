#include <stdio.h>

#define N 10

int main(void) {

    double ident[N][N], *p;
    int num_zeros = N;

    for (p = &ident[0][0]; p <= &ident[N-1][N-1]; p++) {
        if (num_zeros == N) {
            *p = 1.0;
            num_zeros = 0;
        } else {
            *p = 0.0;
            num_zeros++;
        }
    }
    
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%.1lf ", ident[i][j]);
        printf("\n");
    }
    
    return 0;
}
