#include <stdio.h>

#define RECTANGLE 0
#define CIRCLE 1 

struct point {
    int x, y;
};

struct shape {
    int shape_kind;      /* RECTANGLE OR CIRCLE */
    struct point center; /* COORDINATES OF CENTER */
    union {
        struct { 
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
};

double compute_area(struct shape s);
struct shape move_shape(struct shape s, int x_offset, int y_offset);
struct shape scale_shape(struct shape s, double scale_value);

int main(void) {
}

double compute_area(struct shape s) {
    if (s.shape_kind == RECTANGLE)
        return (long) s.u.rectangle.height * s.u.rectangle.width;
    return (long) s.u.circle.radius * s.u.circle.radius * 3.14;
}

struct shape move_shape(struct shape s, int x, int y) {
    struct shape ret = s;
    ret.center.x += x;
    ret.center.y += y;
    return ret;
}

struct shape scale_shape(struct shape s, double c) {
    struct shape ret = s;
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
    } else 
        s.u.circle.radius *= c;
    return ret;
}

