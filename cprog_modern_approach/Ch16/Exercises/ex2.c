#include <stdio.h>

int main(void) {
    struct c {
        double real;
        double imaginary;
    };

    struct c c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3; // (a) and (b)

    c1 = c2; //(c)

    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    printf("c1: %g, %g\nc2: %g, %g\nc3: %g, %g\n", c1.real, c1.imaginary,
                                                   c2.real, c2.imaginary,
                                                   c3.real, c3.imaginary);

    return 0;
}
