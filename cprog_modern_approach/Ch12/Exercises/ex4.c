#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int *top_ptr = &contents[0];

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {
    exit(EXIT_SUCCESS);
}

void make_empty(void) {
    top_ptr = &contents[0];
}

bool is_empty(void) {
    return top_ptr == &contents[0];
}

bool is_full(void) {
    return top_ptr == &contents[STACK_SIZE];
}

void push(char i) {
    if (is_full())
        stack_overflow();
    else
        *top_ptr++ = i;
}

int pop(void) {
    if (is_empty())
        stack_underflow();
    else
        return *--top_ptr;
}

void stack_overflow(void) {
    printf("stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("stack underflow\n");
    exit(EXIT_FAILURE);
}
