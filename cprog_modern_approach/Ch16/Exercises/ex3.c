#include <stdio.h>

struct complex {
    double real;
    double imaginary;
};

struct complex add_complex(struct complex c1, struct complex c2);
struct complex make_complex(double real, double imaginary);

int main(void) {
    struct complex c1, c2, c3, c4;
    c1 = make_complex(1.0, 2.0);
    c2 = make_complex(3.0, 4.0);
    c3 = make_complex(5.0, 6.0);
    c4 = add_complex(c1, c2);
    return 0;
}

struct complex add_complex(struct complex c1, struct complex c2) {
    struct complex c_new;
    c_new.real = c1.real + c2.real;
    c_new.imaginary = c1.imaginary + c2.imaginary;
    return c_new;
}

struct complex make_complex(double real, double imaginary) {
    struct complex c = {.real = real, .imaginary = imaginary};
    return c;
}
