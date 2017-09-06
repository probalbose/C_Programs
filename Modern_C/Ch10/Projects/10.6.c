#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {
    int result;
    char input;
    bool end_of_expr;

    for (;;) {
        // prompt user for expression
        printf("enter an RPN expression: ");

        // evaluate expression
        end_of_expr = false;
        while (end_of_expr == false) {
            scanf(" %c", &input);
            switch (input) {
                // TODO !!!
                case '=': break;
                case '+': break;
                case '-': break;
                case '*': break;
                case '/': break;
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9': 
                          push(atoi(input)); break;
                case '\n': end_of_expr = true; break;
                default:  exit(EXIT_FAILURE); break;
            }
        }
        // print result
        // TODO !!!
    }

    exit(EXIT_SUCCESS);
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(int i) {
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

int pop(void) {
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

void stack_overflow(void) {
    printf("stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("stack underflow\n");
    exit(EXIT_FAILURE);
}
