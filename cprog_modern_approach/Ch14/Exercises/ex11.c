#include <stdio.h>

#define ERROR(str,args) fprintf(stderr, str, args)

int main(void) {
    int index1 = 3;
    ERROR("Range error: index1 = %d\n", index1);
    return 0;
}
