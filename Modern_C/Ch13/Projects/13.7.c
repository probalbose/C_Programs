/* 
 * prints English word for a positive number
 * does not work with negative numbers 
 */

#include <stdio.h>

int main(void) {
    int number, tens, ones;
    char *tens_strs[] = {"","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
    char *ones_strs[] = {"","one","two","three","four","five","six","seven","eight","nine"};
    char *teens_strs[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen", 
                          "sixteen","seventeen","eighteen","nineteen"};

    printf("Enter a two-digit number: ");
    scanf("%02d", &number);

    tens = number / 10;
    ones = number % 10;

    printf("You entered the number ");

    if (number == 0)
        printf("zero\n");
    // three cases: number < 10, 10 <= number < 20, and number >= 20
    else if (number < 10)
        printf("%s\n", ones_strs[ones]);
    else if (number <= 19)
        printf("%s\n", teens_strs[ones]);
    else 
        printf("%s %s\n", tens_strs[tens], ones_strs[ones]);

    return 0;
}
