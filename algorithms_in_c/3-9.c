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
void stack_init(void);
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
	struct node *ret;
    struct s_node *tmp;
    ret = malloc(sizeof(*ret));
    if (!ret)
        terminate("could not pop off the stack");
    tmp = top->next;
    top->next = tmp->next;
    ret = tmp->tree;
    free(tmp);
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

void stack_init(void)
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
    struct node *a, *b, *c, *d, *e;

    stack_init();

    // build tree
    /*
     *           a
     *          / \
     *         b   e
     *        / \
     *       c   d
     *
     */
    a = malloc(sizeof(*a));
    b = malloc(sizeof(*b));
    c = malloc(sizeof(*c));
    d = malloc(sizeof(*d));
    e = malloc(sizeof(*e));

    if (a == NULL || b == NULL || c == NULL || d == NULL || e == NULL)
        terminate("failed to build tree");

    a->data = 'a';
    b->data = 'b';
    c->data = 'c';
    d->data = 'd';
    e->data = 'e';

    a->l = b;
    a->r = e;
    b->l = c;
    b->r = d;
    c->l = z;
    c->r = z;
    d->r = z;
    d->l = z;
    e->r = z;
    e->l = z;
    
    // postorder traversal  
    traverse(a);

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    return 0;
}
