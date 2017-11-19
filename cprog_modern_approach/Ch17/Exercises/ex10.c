#include <stdio.h>
#include <stdlib.h>

struct part {
    int number;
    char name[20];
    int on_hand;
};

void print_part(struct part *p);

int main(void) {
    return 0;
}

void print_part(struct part *p) {
    printf("Part number: %d\n", p->number);
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
}
