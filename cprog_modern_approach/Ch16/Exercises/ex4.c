#include <stdio.h>

typedef struct {
    double real, imaginary;
} Complex;

Complex add_complex(Complex c1, Complex c2);
Complex make_complex(double real, double imaginary);
void print_complex(Complex c1);

int main(void) {
    Complex c1, c2, c3, c4;

    c1 = make_complex(1.0, 2.0);
    c2 = make_complex(3.0, 4.0);
    c3 = make_complex(5.0, 6.0);
    c4 = add_complex(c1, c2);

    printf("c1 - ");
    print_complex(c1);
    printf("c2 - ");
    print_complex(c2);
    printf("c3 - ");
    print_complex(c3);
    printf("c4 - ");
    print_complex(c4);

    return 0;
}

Complex add_complex(Complex first, Complex second) {
    Complex ret = {first.real+second.real, first.imaginary+second.imaginary};
    return ret;
    //return (Complex) {first.real+second.real, first.imaginary+second.imaginary};
}

Complex make_complex(double real, double imaginary) {
    return (Complex) {real, imaginary};
}

void print_complex(Complex c) {
    printf("real: %g, imaginary: %g\n", c.real, c.imaginary);
}
