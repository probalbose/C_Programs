#include <stdio.h>

#define NAMELEN 20

struct part {
    int number;
    char name[NAMELEN+1];
    int on_hand;
};

int compare_parts(const void *p, const void *q);

int main(void) {
    return 0;
}

int compare_parts(const void *p, const void *q) {
    return (-1 * (((struct part *) p)->number -
                  ((struct part *) q)->number));
}
