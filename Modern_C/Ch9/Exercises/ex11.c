#include <stdio.h>
#include <ctype.h>

float compute_gpa(char grades[], int n);

int main(void) {
    int n = 3, i;
    char grades[] = {'A', 'A', 'A'};

    printf("gpa: %.1f\n", compute_gpa(grades, n));
    return 0;
}

float compute_gpa(char grades[], int n) {
    float gpa;
    int sum = 0, i;
    for (i = 0; i < n; i++) {
        if (toupper(grades[i]) == 'A')
            sum += 4;
        else if (toupper(grades[i]) == 'B')
            sum += 3;
        else if (toupper(grades[i]) == 'C')
            sum += 2;
        else if (toupper(grades[i]) == 'D')
            sum += 1;
        else
            continue;
    }
    printf("dividing %d by %d...\n", sum, n);
    gpa = (float) sum / (float) n;
    return gpa;
}
