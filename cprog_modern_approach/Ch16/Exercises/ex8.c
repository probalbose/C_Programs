#include <stdio.h>

struct color {
    int red;
    int green;
    int blue;
};

int main(void) {
    const struct color MAGENTA = {.red=255, .blue=255};
    printf("red: %d\ngreen: %d\nblue: %d\n", MAGENTA.red, MAGENTA.green, MAGENTA.blue);

    return 0;
}
