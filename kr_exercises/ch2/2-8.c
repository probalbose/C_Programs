/* rightrot(x,n): returns the value of the integer x rotated to the right by 
 * n bit positions.
 *
 * Scenarios
 * -
 *
 * Constants
 * -
 *
 * Changing Data
 * -
 *
 * Outline
 * -
 */

#include <stdio.h>

int rightrot(int x, int n);

int main(void)
{
    int x = 7;
    int n = 2;
    printf("rightrot(%d, %d): %d\n", x, n, rightrot(x, n));
    return 0;
}

int rightrot(int x, int n)
{
    return x >> n;
}

