#include <stdio.h>

int day_of_year(int day, int month, int year);

int main(void) {
    int day, month, year;

    printf("enter a day, month, and year separated by spaces: ");
    scanf("%d %d %d", &day, &month, &year);

    printf("day of the year: %d\n", day_of_year(day, month, year));
    return 0;
}

int day_of_year(int day, int month, int year) {
    int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_count = 0, i;

    for (i = 0; i < month-1; i++)
        day_count += num_days[i];
    if (year % 4 == 0 && month > 2)
        day_count++;
    return day_count + day;
}
