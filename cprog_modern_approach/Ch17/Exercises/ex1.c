#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t bytes);

int main(void) {
    int n, *p;
    printf("enter bytes of memory to allocate: ");
    scanf("%d", &n);
    p = my_malloc((size_t) n);
    free(p);
    exit(EXIT_SUCCESS);
}

void *my_malloc(size_t bytes) {
    void * p = malloc(bytes);
    if (p == NULL) {
        printf("malloc() failed in my_malloc()\n");
        exit(EXIT_FAILURE);
    } else
        return p;
}
