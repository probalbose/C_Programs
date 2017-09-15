#include <stdio.h>
#include <stdbool.h>

bool search(const int a[], int n, int key);

int main(void) {
    int temperatures[7][24] = {0};

    temperatures[6][23] = 32;

    if (search(temperatures[0], 7*24, 22))
        printf("found the temp\n");
    else
        printf("no temp found\n");

    return 0;
}
bool search(const int a[], int n, int key) {
    const int *p;

    for (p = a; p < a + n; p++) {
        if (*p == key)
            return true;
    }

    return false;
}
