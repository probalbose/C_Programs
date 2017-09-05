// prompt user for isbn number & print its components

#include <stdio.h>

int main(void)
{
    int gs1, group, pub, item_no, check_digit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1, &group, &pub, &item_no, &check_digit);

    printf("GS1 prefix: %d\n", gs1);
    printf("Group identifier: %d\n", group);
    printf("Publisher code: %d\n", pub);
    printf("Item number: %d\n", item_no);
    printf("Check digit: %d\n", check_digit);

    return 0;
}
