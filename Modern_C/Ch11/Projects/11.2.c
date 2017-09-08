/* display closest departure and arrival time */

#include <stdio.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void) {

    int hour, minute, since_midnight, departure_time, arrival_time;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    since_midnight = hour * 60 + minute;
    
    find_closest_flight(since_midnight, &departure_time, &arrival_time);

    printf("closest departure time is %04d, arriving at %04d\n", departure_time, arrival_time);
    
    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {
    if (desired_time < (8 * 60)) {
        *departure_time = 800;
        *arrival_time = 1016;
    }

    else if (desired_time < 9 * 60 + 43) {
        if (desired_time - (8 * 60) < (9 * 60 + 43) - desired_time) {
            *departure_time = 800;
            *arrival_time = 1016;
        }
        else {
            *departure_time = 943;
            *arrival_time = 1152;
        }
    }

    else if (desired_time < 11 * 60 + 19) {
        if (desired_time - (9 * 60 + 43) < (11 * 60 + 19) - desired_time) {
            *departure_time = 943;
            *arrival_time = 1152;
        }
        else {
            *departure_time = 1119;
            *arrival_time = 1331;
        }
    }

    else if (desired_time < 12 * 60 + 47) {
        if (desired_time - (11 * 60) + 19 < (12 * 60 + 47) - desired_time) {
            *departure_time = 1119;
            *arrival_time = 1331;
        }
        else {
            *departure_time = 1247;
            *arrival_time = 1500;
        }
    }

    else if (desired_time < 14 * 60) {
        if (desired_time - (12 * 60 + 47) < (14 * 60) - desired_time) {
            *departure_time = 1247;
            *arrival_time = 1500;
        }
        else {
            *departure_time = 1400;
            *arrival_time = 1608;
        }
    }

    else if (desired_time < 15 * 60 + 45) {
        if (desired_time - (14 * 60) < (15 * 60 + 45) - desired_time) {
            *departure_time = 1400;
            *arrival_time = 1608;
        }
        else {
            *departure_time = 1545;
            *arrival_time = 1755;
        }
    }

    else if (desired_time < 19 * 60) {
        if (desired_time - (15 * 60 + 45) < (19 * 60) - desired_time) {
            *departure_time = 1545;
            *arrival_time = 1755;
        }
        else {
            *departure_time = 1900;
            *arrival_time = 2120;
        }
    }

    else {
        if (desired_time - (19 * 60) < (21 * 60 + 45) - desired_time) {
            *departure_time = 1900;
            *arrival_time = 2120;
        }
        else {
            *departure_time = 2145;
            *arrival_time = 2358;
        }
    }
}
