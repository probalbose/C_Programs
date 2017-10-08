// Accept a date from user in the form mm/dd/yyyy and print it in the form yyyymmdd

#include<stdio.h>

int main(void) 
{
    int year, month, day;

    printf("Enter the date in the form mm/dd/yyyy: ");
    scanf("%d / %d / %d", &month, &day, &year);

    printf("You entered: %d%02d%d\n", year, month, day);

    return 0;
}
