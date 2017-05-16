// take a 24-hour time and print a 12-hour time

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int hour, minute;
    bool pm_flag;

    printf("Enter a 24-hour time (xx:xx): ");
    scanf("%2d:%2d", &hour, &minute);

    // AM or PM?
    pm_flag = (hour > 11) ? true : false;

    // catch special times midnight or noon
    if(hour == 0 || hour == 12)
        hour = 12; 
    else
        hour %= 12;

    if(pm_flag)
        printf("The time is %d:%d PM.\n", hour, minute);
    else
        printf("The time is %d:%d AM.\n", hour, minute);
    return 0;
}
