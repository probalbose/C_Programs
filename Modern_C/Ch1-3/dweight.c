// Computes the dimensional weight of a container
// expects height, length, and width in inches to be supplied at command line

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int height = 12, length = 10, width = 8, volume;

    volume = height * length * width;

    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", 
            (volume + 165) / 166);

    return 0;
}

