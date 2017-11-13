// write parameterized macros:
// (a) the cube of x
// (b) remainder when n is divided by 4
// (c) 1 if the product of x and y is less than 100, 0 otherwise

#include <stdio.h>

#define CUBE(x) x*x*x
#define REM4(n) ((n) % 4)
#define ONE(x,y) ((x)*(y) < 100 ? 1 : 0)

int main(void) {
    printf("CUBE(3) = %d\n", CUBE(3)); //27
    printf("REM4(7) = %d\n", REM4(7)); //3
    printf("ONE(10,11) = %d\n", ONE(10,11)); //0
    return 0;
}
