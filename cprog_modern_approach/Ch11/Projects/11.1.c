// Prompt user for a dollar amount and then tell user how to pay that amount
// using the smallest number of $20, $10, $5, and $1 bills

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
    int twenties = 0, tens = 0, fives = 0, ones = 0;
    int amount, i;

    printf("Enter an amount in USD: ");
    scanf("%d", &amount);

    pay_amount(amount, &twenties, &tens, &fives, &ones);

    // Print results
    printf("Twenties: %d\n", twenties);
    printf("Tens: %d\n", tens);
    printf("Fives: %d\n", fives);
    printf("Ones: %d\n", ones);

    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    // Calculate # of times each bill goes into amount
    int amount = dollars;

    *twenties = amount / 20;
    amount = amount - (*twenties * 20);

    *tens = amount / 10;
    amount = amount - (*tens * 10);

    *fives = amount / 5;
    amount = amount - (*fives * 5);

    *ones = amount;
}
