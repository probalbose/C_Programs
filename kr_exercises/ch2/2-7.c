// borrowed this solution from Jeremy Yu AKA ccpalletes on github...
// bit manipulation is a bit boring...

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
    printf("%u\n", invert(15,3,2));
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned bitmask = ~(~0 << n) << (p + 1 - n);
    return x ^ bitmask;
}

