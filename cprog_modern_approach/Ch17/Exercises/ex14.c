#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

void delete_from_list(struct node **list, int n);

int main(void) {
    return 0;
}

void delete_from_list(struct node **list, int n) {
    struct node *cur, *prev;

    for (cur = *list, prev = NULL;
         cur != NULL && cur->val != n;
         prev = cur, cur = cur->next)
        ;

    // n not found
    if (cur == NULL)
        ;
    // n was in the first node
    else if (prev == NULL)
        *list = (*list)->next;
    // n was in some other node
    else
        prev->next = cur->next;
    free(cur);
}
