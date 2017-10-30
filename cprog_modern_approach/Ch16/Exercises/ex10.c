#include <math.h>
#include <stdbool.h>
#include <stdio.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

double compute_area(struct rectangle r);
bool is_in(struct point p, struct rectangle r);
struct point compute_center(struct rectangle r);
struct rectangle move_rect(struct rectangle r, int x_offset, int y_offset);

int main(void) {
    return 0;
}

double compute_area(struct rectangle r) {
    double w, h;
    w = fabs((float) r.upper_left.x - (float) r.lower_right.x);
    h = fabs((float) r.upper_left.y - (float) r.lower_right.y);
    return (double) w * h;
}

bool is_in(struct point p, struct rectangle r) {
    if (p.x >= r.upper_left.x && p.x <= r.lower_right.x) 
        if (p.y >= r.lower_right.y && p.y <= r.upper_left.y)
            return true;
    return false;
}

struct point compute_center(struct rectangle r) {
    struct point center;
    center.x = (r.upper_left.x - r.lower_right.x) / 2;
    center.y = (r.upper_left.y - r.lower_right.y) / 2;
    return center;
}

struct rectangle move_rect(struct rectangle r, int x_offset, int y_offset) {
    struct rectangle ret = r;
    ret.upper_left.x += x_offset;
    ret.upper_left.y += y_offset;
    ret.lower_right.x += x_offset;
    ret.lower_right.y += y_offset;
    return ret;
}
