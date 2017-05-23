/* display closest departure and arrival time */

#include <stdio.h>

int main(void) {

    int hour, minute, since_midnight;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    since_midnight = (hour * 60) + minute;
    if (since_midnight < (8 * 60))
        printf("Closest departure time is 8:00 AM, arriving at 10:16 AM.\n");

    else if (since_midnight < 9 * 60 + 43)
        if (since_midnight - (8 * 60) < (9 * 60 + 43) - since_midnight)
            printf("Closest departure time is 8:00 AM, arriving at 10:16 AM.\n");
        else
            printf("Closest departure time is 9:43 AM, arriving at 11:52 AM.\n");

    else if (since_midnight < 11 * 60 + 19)
        if (since_midnight - (9 * 60 + 43) < (11 * 60 + 19) - since_midnight)
            printf("Closest departure time is 9:43 AM, arriving at 11:52 AM.\n");
        else
            printf("Closest departure time is 11:19 AM, arriving at 1:31 PM.\n");

    else if (since_midnight < 12 * 60 + 47)
        if (since_midnight - (11 * 60) + 19 < (12 * 60 + 47) - since_midnight)
            printf("Closest departure time is 11:19 AM, arriving at 1:31 PM.\n");
        else
            printf("Closest departure time is 12:47 PM, arriving at 3:00 PM.\n");

    else if (since_midnight < 14 * 60)
        if (since_midnight - (12 * 60 + 47) < (14 * 60) - since_midnight)
            printf("Closest departure time is 12:47 PM, arriving at 3:00 PM.\n");
        else
            printf("Closest departure time is 2:00 PM, arriving at 4:08 PM.\n");

    else if (since_midnight < 15 * 60 + 45)
        if (since_midnight - (14 * 60) < (15 * 60 + 45) - since_midnight)
            printf("Closest departure time is 2:00 PM, arriving at 4:08 PM.\n");
        else
            printf("Closest departure time is 3:45 PM, arriving at 5:55 PM.\n");

    else if (since_midnight < 19 * 60)
        if (since_midnight - (15 * 60 + 45) < (19 * 60) - since_midnight)
            printf("Closest departure time is 3:45 PM, arriving at 5:55 PM.\n");
        else 
            printf("Closest departure time is 7:00 PM, arriving at 9:20 PM.\n");

    else 
        if (since_midnight - (19 * 60) < (21 * 60 + 45) - since_midnight)
            printf("Closest departure time is 7:00 PM, arriving at 9:20 PM.\n");
        else 
            printf("Closest departure time is 9:45 PM, arriving at 11:58 PM.\n");

    return 0;
}
