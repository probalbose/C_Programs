/* bitcount(x): return # of 1 bits in x
 * if x == 010, then x - 1 == 001. (x & (x - 1)) shifts rightmost
 * 1 bit to the right in x.
 * if x == 011, then x - 1 == 010. (x & (x - 1)) == (x - 1)
 * we can use these relationships to write a new decrementing clause
 * in the for loop of bitcount.
 *
 */

#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
    unsigned x = 3;
    // bitcount(011) is 2
    printf("bitcount(%u) is %d.\n", x, bitcount(x)); 
    return 0;
}

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x - 1))
        ++b;
    return b;
}

