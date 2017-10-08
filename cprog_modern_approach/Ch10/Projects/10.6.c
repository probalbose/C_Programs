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
    int term1, term2;
    char input;

    for (;;) {
        // prompt user for expression
        printf("enter an RPN expression (q to quit): ");

        // evaluate expression
        while (true) {
            scanf(" %c", &input);
            switch (input) {
                case '=': printf("value of expression: %d\n", pop()); 
                          make_empty(); 
                          break;
                case '+': term2 = pop();
                          term1 = pop();
                          push(term1 + term2);
                          break;
                case '-': term2 = pop();
                          term1 = pop();
                          push(term1 - term2);
                          break;
                case '*': term2 = pop();
                          term1 = pop();
                          push(term1 * term2);
                          break;
                case '/': term2 = pop();
                          term1 = pop();
                          push(term1 / term2);
                          break;
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9': 
                          push(input - '0'); // convert char to int before push
                          break;
                case 'q': exit(EXIT_SUCCESS);
                          break;
                default:  printf("invalid input. try again.\n"); 
                          make_empty();
                          break;
            }
            if (is_empty())
                break;
        }
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
