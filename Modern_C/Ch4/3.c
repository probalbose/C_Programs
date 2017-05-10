// Write a program that asks the user to enter a 3-digit number
// Print that number in reverse

#include <stdio.h>

int main(void)
{
    int i, j, k;
    printf("Enter a 3-digit number: ");
    scanf("%1d%1d%1d", &i, &j, &k);
    printf("Reversed number: %d%d%d\n", k, j, i);
    return 0;
}
