/* find largest and smallest of four integers entered by user */

#include <stdio.h>

int main(void) {
    int i1, i2, i3, i4;
    int max, min;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &i1, &i2, &i3, &i4);

    max = i1;
    min = i1;

    if (i2 > max)
        max = i2;
    else if (i2 < min)
        min = i2;

    if (i3 > max)
        max = i3;
    else if (i3 < min)
        min = i3;

    if (i4 > max)
        max = i4;
    else if (i4 < min)
        min = i4;

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);

    return 0;
}
