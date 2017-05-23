/* display date that comes first on the calendar */

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int year1, year2, month1, month2, day1, day2;
    bool first = false, second = false;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%02d/%02d/%02d", &month1, &day1, &year1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%02d/%02d/%02d", &month2, &day2, &year2);
    
    // year
    if (year1 < year2)
        first = true;
    else if (year2 < year1)
        second = true;
    else
        // month
        if (month1 < month2)
            first = true;
        else if (month2 < month1)
            second = true;
        else
            // day
            if (day1 < day2)
                first = true;
            else if (day2 < day1)
                second = true;

    if (first)
        printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d.\n", month1, day1, year1,
                month2, day2, year2);
    else if (second)
        printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d.\n", month2, day2, year2,
                month1, day1, year1);
    else
        printf("Dates are the same.\n");

    return 0;
}
