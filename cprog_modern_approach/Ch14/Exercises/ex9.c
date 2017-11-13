#include <stdio.h>

#define CHECK(x,y,n) ((x) < n && (x) >= 0 && (y) < n && (y) >= 0 ? 1 : 0)
#define MEDIAN(x,y,z) 
#define POLYNOMIAL(x) 

int main(void) {
    printf("CHECK(%d,%d,%d) = %d\n", 3, 4, 100, CHECK(3,4,100));
    printf("CHECK(%d,%d,%d) = %d\n", 101, 23, 100, CHECK(101,23,100));
    return 0;
}
