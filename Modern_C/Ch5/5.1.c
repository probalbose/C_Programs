// calculate how many digits a number contains

#include <stdio.h>

int main(void) {
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);

    // catch negative numbers
    if(input < 0)
        input *= -1;

    // figure out the digits
    if(input < 10)
        printf("The number %d has 1 digit\n", input);
    else if(input < 100)
        printf("The number %d has 2 digits\n", input);
    else if(input < 1000)
        printf("The number %d has 3 digits\n", input);
    else if(input < 10000)
        printf("The number %d has 4 digits\n", input);
    else
        printf("Number has more than 4 digits.\n");
    return 0;
}
