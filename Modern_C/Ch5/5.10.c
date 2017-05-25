/* convert a numerical grade into a letter grade */

#include <stdio.h>

int main(void) {
    int grade, tens, ones;

    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    if (grade > 100)
        printf("Grade is greater than 100.\n");
    else if (grade == 100)
        printf("A");
    else if (grade < 0)
        printf("Grade is less than 0.\n");
    else {
        tens = grade / 10;
        printf("Letter grade: ");
        switch (tens) {
            case 9:  printf("A\n");
                     break;
            case 8:  printf("B\n");
                     break;
            case 7:  printf("C\n");
                     break;
            case 6:  printf("D\n");
                     break;
            default: printf("F\n");
                     break;
        }
    }
    return 0;
}
