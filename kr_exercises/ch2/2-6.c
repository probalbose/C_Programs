/* setbits(x,p,n,y): returns x with n bits beginning at position p
 * set to rightmost n bits of y, leaving other bits unchanged
 *
 * Scenarios
 * - program prints output
 *
 * Constants
 * - unsigned x
 * - unsigned y
 *
 * Changing Data
 *
 * Outline
 * - setbit() parameters are defined in main
 * - main calls printf("%d\n", setbits(x,n,p,y));
 * - setbits()
 *   - make bitmask that masks out all but the n rightmost bits
 *   - & the bitmask with y to get the rightmost n bits of y
 *   - shift the value obtained in above step to the left so that
 *     n bits are inserted at position p of x
 *   - mask out all but the n bits of x starting at position p
 *   - and above value with original x
 */
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    int start = 4;
    int numbits = 3;
    unsigned x;
    unsigned y;

    printf("%d\n", setbits(x, start, numbits, y));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned bitmask = ~((~0) << n);
    return ((bitmask & y) << p) | (~(bitmask << p) & x);
}

