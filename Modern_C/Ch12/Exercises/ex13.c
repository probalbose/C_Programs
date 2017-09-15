#include <stdio.h>

#define N 10

void make_ident(double matrix[N][N]);

int main(void) {
    double ident[N][N];

    make_ident(ident);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%.1lf ", ident[i][j]);
        printf("\n");
    }

    return 0;
}

void make_ident(double matrix[N][N]) {
    int n=N;
    double *p;

    for (p = &matrix[0][0]; p <= &matrix[N-1][N-1]; p++) {
        if (n == N) {
            *p = 1.0;
            n = 0;
        }
        else {
            *p = 0.0;
            n++;
        }
    }
}
