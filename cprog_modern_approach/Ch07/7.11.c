/* Take first & last name entered by the user & then display last name, comma, & first initial */

#include <stdio.h>

int main(void) {
    char initial, input;

    printf("enter a first & last name: ");

    // get first initial
    scanf("%c", &initial);

    // skip to last name
    while (getchar() != ' ')
        ;

    // print last name
    while ((input = getchar()) != '\n')
        printf("%c", input);

    // print the rest
    printf(", %c.\n", initial);

    return 0;
}
