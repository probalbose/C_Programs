/* ask user to enter amount of taxable income and display the tax due */

#include <stdio.h>

float income_tax(float income);

int main(void) {

    float income;

    printf("Enter taxable income: ");
    scanf("%f", &income);

    printf("Tax on %.2f is %.2f\n", income, income_tax(income));

    return 0;
}

float income_tax(float income) {
    float tax;

    if (income <= 750)
        tax = .01f * income;
    else if (income <= 2250)
        tax = 7.50f + .02f * (income - 750);
    else if (income <= 3750)
        tax = 37.50f + .03f * (income - 2250);
    else if (income <= 5250)
        tax = 82.50f + .04f * (income - 3750);
    else if (income <= 7000)
        tax = 142.50f + .05f * (income - 5250);
    else 
        tax = 230.00f + .06f * (income - 7000);

    return tax;
}
