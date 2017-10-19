// no, there is no problem using quotes instead of <> when including system headers, 
// so long as there is not a header of the same name in the working directory

#include "stdio.h"

int main(void) {
    printf("test\n");
    return 0;
}
