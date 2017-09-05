/*
 * five students, five quizzes
 * compute total and average scores for each student
 * compute average, high, and low score for each quiz
 */

#include <stdio.h>

int main(void) {
    char input;
    const int scores[5][5];
    int row_sum, col_sum, high_score, low_score, i, j;

    // fill scores multi-dimensional array
    for (i = 0; i < 5; i++) {
        printf("enter student %d's scores (0-100): ", i+1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    // student stats
    for (i = 0; i < 5; i++) {
        row_sum = 0;
        for (j = 0; j < 5; j++)
            row_sum += scores[i][j];
        printf("student %d total, average:  %d, %.2f\n", i+1, row_sum, (float) row_sum / 5.0);
    }

    // quiz stats
    for (i = 0; i < 5; i++) {
        col_sum = 0;
        high_score = 0;
        low_score = 101;
        for (j = 0; j < 5; j++) {
            col_sum += scores[j][i];
            if (scores[j][i] > high_score)
                high_score = scores[j][i];
            else if (scores[j][i] < low_score)
                low_score = scores[j][i];
        }
        printf("Quiz %d average, high, and low: %.2f, %d, %d\n", i+1, (float) col_sum / 5.0, 
                high_score, low_score);
    }

    printf("\n");
    return 0;
}
