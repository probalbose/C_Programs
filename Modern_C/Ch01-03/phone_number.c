// prompt user for phone number in the form (xxx) xxx-xxxx
// and print phone number in the form xxx.xxx.xxxx

#include <stdio.h>

int main(void)
{
    int area_code, three_digits, four_digits;

    printf("Enter phone number (xxx) xxx-xxxx: ");
    scanf("(%d) %d-%d", &area_code, &three_digits, &four_digits);

    printf("You entered %d.%d.%d.\n", area_code, three_digits, four_digits);
    return 0;
}

