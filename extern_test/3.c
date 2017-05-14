#include <stdio.h>
#include "1.h"
#include "2.c"

int main(void)
{
    printf("%d\n", test_var++);
    printf("%d\n", test_var++);
    return 0;
}
