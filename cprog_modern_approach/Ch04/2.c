// Write a program that asks the user to enter a 3-digit number
// Print that number in reverse

#include <stdio.h>

int main(void)
{
    int i, j, k;
    printf("Enter a 3-digit number: ");
    scanf("%3d", &i);
    j = i % 100; // last 2 digits of number
    k = i / 100; // first digit of number
    i = j / 10; // middle digit
    j = j % 10; // last digit
    printf("Reversed number: %d%d%d\n", j, i, k);
    return 0;
}
