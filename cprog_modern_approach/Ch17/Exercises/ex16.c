#include <stdio.h>
#include <stdlib.h>

int g(int i);
int sum(int (*f)(int), int start, int end);

int main(void) {
    int s, e;
    printf("enter start: ");
    scanf(" %d", &s);
    printf("enter end: ");
    scanf(" %d", &e);
    printf("sum of g(start)+...+g(end): %d\n", sum(g, s, e));
    return 0;
}

int g(int i) {
    return i;
}

int sum(int (*f)(int), int start, int end) {
    int ret = 0, i;
    for (i = start; i <= end; i++)
        ret += (*f)(i);
    return ret;
}
