// Prompt user for loan amount and interest rate
// Print the remaining balance after the first, second, and third
// monthly payments

#include <stdio.h>

float mature(float loan, float interest, float payment);

int main(void) 
{
    float loan, interest_rate, monthly_payment, monthly_rate;

    // Get loan amount, interest rate, and monthly payment from user
    printf("Enter loan amount: ");
    scanf("%f", &loan);

    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    interest_rate = (interest_rate / 100.00);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    // Calculate monthly interest rate
    monthly_rate = interest_rate / 12.0;
    printf("Monthly interest rate: %.2f\n", monthly_rate);

    // Add monthly interest to balance and then subtract monthly payment
    loan = mature(loan, monthly_rate, monthly_payment);
    printf("Balance after first month: %.2f\n", loan);
    loan = mature(loan, monthly_rate, monthly_payment);
    printf("Balance after second month: %.2f\n", loan);
    loan = mature(loan, monthly_rate, monthly_payment);
    printf("Balance after third month: %.2f\n", loan);
    
    return 0;
}

float mature(float loan, float monthly_interest, float monthly_payment)
{
    loan = loan + (loan * monthly_interest);
    loan = loan - monthly_payment;
    return loan;
}
