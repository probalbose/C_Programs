#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *find_last(struct node *list, int n);

int main(void) {
    return 0;
}

struct node *find_last(struct node *list, int n) {
    struct node *p = NULL;
    for (; list->next != NULL; list = list->next) {
        if (list->val == n) {
            p->val = list->val;
            p->next = list->next;
        }
    }
    return p;
}
