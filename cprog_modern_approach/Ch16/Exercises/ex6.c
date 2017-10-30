#include <stdio.h>

struct time {
    int hours, minutes, seconds;
};

struct time split_time(long total_seconds);

int main(void) {
    long total_seconds = 10000;
    struct time t = split_time(total_seconds);
    printf("hour: %d\nminute: %d\nsecond: %d\n", t.hours, t.minutes, t.seconds);
    return 0;
}

struct time split_time(long total_seconds) {
    int hours = total_seconds / 3600;
    total_seconds %= 3600;
    int minutes = total_seconds / 60;
    total_seconds %= 60;
    int seconds = total_seconds;

    return (struct time) {hours, minutes, seconds};
}
