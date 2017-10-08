#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {
    char ch, matching;
    bool nested = true;

    printf("enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n') {
        if (ch == '(' || ch == '{') {
            //printf("pushing chars to the stack\n");
            push(ch);
        }
        else if (ch == ')') {
            matching = pop();
            if (matching != '(')
                nested = false;
        }
        else if (ch == '}') {
            matching = pop();
            if (matching != '{') 
                nested = false;
        }
        else
            printf("invalid character entered; ignoring...\n");
    }

    if (is_empty() != true)
        printf("parentheses/braces are not nested properly\n");
    else if (nested == false)
        printf("parentheses/braces are not nested properly\n");
    else
        printf("parentheses/braces are nested properly\n");

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

void push(char i) {
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

char pop(void) {
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
