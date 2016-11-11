#include <stdio.h>
#include <limits.h>

/* 2-1: print limits, both signed and unsigned, of chars, ints, longs, shorts, floats, etc.
 */

int main()
{
    printf("char min: %d\n", CHAR_MIN);
    printf("char max: %d\n", CHAR_MAX);
    printf("unsigned char max: %d\n", UCHAR_MAX);
    printf("int min: %d\n", INT_MIN);
    printf("int max: %d\n", INT_MAX);
    printf("unsigned int max: %d\n", UINT_MAX);
    printf("long max: %d\n", LONG_MAX);
    printf("long min: %d\n", LONG_MIN);
    printf("unsigned long max: %d\n", ULONG_MAX);
    printf("short max: %d\n", SHRT_MAX);
    printf("short min: %d\n", SHRT_MIN);
    printf("unsigned short max: %d\n", USHRT_MAX);
    return 0;
}

