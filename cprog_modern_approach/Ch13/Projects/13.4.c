// echo command-line args in reverse order

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // iterate thru args backwards
    for (int i = argc - 1; i >= 1; i--)
        printf("%s ", argv[i]);
    printf("\n");
    return 0;
}
