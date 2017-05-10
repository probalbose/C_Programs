// Write a program that asks the user to enter a 2-digit number
// Print that number in reverse

#include <stdio.h>

int main(void)
{
    int i, j;
    printf("Enter a 2-digit number: ");
    scanf("%2d", &i);
    j = i % 10; // last digit of number
    i = i / 10; // first digit of number
    printf("Reversed number: %d%d\n", j, i);
    return 0;
}
