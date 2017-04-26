/* Calculate the volume of a sphere */

#include <stdio.h>

int main(void)
{
    float radius;

    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);
    printf("%f\n", (4.0f / 3.0f) * 3.14 * radius * radius);
    return 0;
}
