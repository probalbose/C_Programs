#include <stdio.h>

int main(void) {
    char *months[] = {"","January","February","March","April","May",
                      "June","July","August","September","October",
                      "November","December"};
    int m, d, y;

    // get input in form of mm/dd/yyyy
    printf("enter a date (mm/dd/yyyy): ");
    scanf(" %d/%d/%d", &m, &d, &y);
    // print month day, year
    printf("you entered %s %d, %d\n", months[m], d, y);
    return 0;
}
