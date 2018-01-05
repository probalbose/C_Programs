/*
 * =====================================================================================
 *
 *       Filename:  3-5.c
 *
 *    Description:  write procedures for insertion and deletion in a doubly linked list
 *
 *        Version:  1.0
 *        Created:  01/05/2018 02:05:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  scott myers
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *make_node(int d);
void insert(struct node *p);
void delete(struct node *p);
struct node *find_node(int d);
void clean_up(struct node *p);

struct node *head, *tail;

int main(void)
{
    struct node *p;

    head->next = tail;
    head->prev = NULL;
    tail->next = tail;
    tail->prev = head;
    
    // create list
    for (int i = 0; i < 10; i++) {
        p = make_node(i);
        printf("made a node...\n");
        insert(p);
        printf("inserted a node...\n");
    }
    // insert a few nodes
    //
    // find a particular node
    //
    // delete it
    //
    // clean up
    //
    // exit
}

struct node *make_node(int d)
{
    struct node *node_ptr;

    node_ptr = malloc(sizeof(*node_ptr));
    if (node_ptr == NULL) {
        fprintf(stderr, "could not make node in make_node()");
        exit(EXIT_FAILURE);
    }

    node_ptr->data = d;
    return node_ptr;
}

void insert(struct node *p)
{
    struct node *old_end;
    old_end = tail->prev;
    tail->prev = p;
    p->next = tail;
    p->prev = old_end;
    old_end->next = p;
}

void delete(struct node *p)
{
    free(p);
}

struct node *find_node(int d)
{
    struct node *node_ptr;

    node_ptr = head->next;
    while(node_ptr->data != d);
        node_ptr = node_ptr->next;

    if (node_ptr == tail) {
        fprintf(stderr, "node not found");
        return NULL;
    }

    return node_ptr;
}

void clean_up(struct node *node_ptr)
{
    struct node *prev_node;

    while(node_ptr != tail) {
        prev_node = node_ptr;
        node_ptr = node_ptr->next;
        free(prev_node);
    }
    delete(tail);
}


