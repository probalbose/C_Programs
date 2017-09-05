/* add 5% tax to an amount and print the result */
#include <stdio.h>

int main(void)
{
    float amount;
    
    printf("Enter an amount: ");
    scanf("%f", &amount);

    printf("With tax added: $%.2f\n", (amount + (0.05 * amount)));
    return 0;
}

