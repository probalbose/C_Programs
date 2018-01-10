/*
 * =====================================================================================
 *
 *       Filename:  3-9.c
 *
 *    Description:  stack-based postorder traversal of binary tree
 *
 *        Version:  1.0
 *        Created:  01/10/2018 05:09:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *l, *r;
};

struct s_node {
    struct node *tree;
    struct s_node *next;
};

// dummy / external node
struct node *z;

// stack nodes
struct s_node *top, *bottom;

struct node *peek(void);
struct node *pop(void);
void push(struct node *t);
void stackinit(void);
bool stack_empty(void);
void terminate(const char *msg);
void traverse(struct node *t);
void visit(struct node *t);

struct node *peek(void)
{
	// return tree node at top of stack without modifying the stack
	return top->next->tree;
}

struct node *pop(void)
{
	struct node *ret = top->next->tree;
	top->next = top->next->next;
	return ret;
}

void push(struct node *p)
{
	struct s_node *ins, *tmp;
	ins = malloc(sizeof(*ins));
	if (ins == NULL)
		terminate("could not push to stack");
    tmp = top->next;
    ins->tree = p;
    ins->next = tmp;
    top->next = ins;
}

bool stack_empty(void)
{
    return top->next == bottom;
}

void stackinit(void)
{
    // dummy node
    z = malloc(sizeof(*z));
    if (z == NULL)
        terminate("could not initialize stack");
    z->data = 0;
    z->l = z;
    z->r = z;

    // stack
    top = malloc(sizeof(*top));
    bottom = malloc(sizeof(*bottom));
    if (top == NULL || bottom == NULL)
        terminate("could not initialize stack");
    top->tree = z;
    top->next = bottom;
    bottom->tree = z;
    bottom->next = bottom;
}

void terminate(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

void traverse(struct node *t)
{
    // Postorder traversal: visit left subtree, then right subtree, then root
  
    struct node *prev = NULL;
    push(t);
    while (!stack_empty()) {
        t = peek();

        /* going down the tree...
           go left, if possible
           else go right, if possible
           else, visit node and go up */
        if (!prev || prev->l == t || prev->r == t) {
            if (t->l !=z)
                push(t->l);
            else if (t->r != z)
                push(t->r);
            else {
                t = pop();
                visit(t);
            }
        }

        /* coming up from the left...
           go right, if possible
           else visit and go up */
        else if (prev == t->l) {
            if (t->r != z)
                push(t->r);
            else {
                t = pop();
                visit(t);
            }
        }
        
        /* coming up from the right...
           visit and go up again, if possible */
        else if (prev == t->r) {
            t = pop();
            visit(t);
        } 
        prev = t;
    }
}

void visit(struct node *t)
{
    printf("%c\n", t->data);
}

int main(void)
{
    //!!! TODO: implement driver code
    return 0;
}
