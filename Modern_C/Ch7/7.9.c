/* Write a program that asks the user for a 12-hour time, then displays
 * the time in 24-hour form.
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int hour, minute;
    char a_or_p;

    printf("enter a 12-hour time: ");
    scanf("%2d:%2d %c", &hour, &minute, &a_or_p);

    a_or_p = toupper(a_or_p);

    if (a_or_p == 'P')
        hour += 12;

    printf("equivalent 24-hour time: %02d:%02d\n", hour, minute);

    return 0;
}
