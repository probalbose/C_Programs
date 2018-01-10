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

void clean_up(struct node *p);
void del_node(struct node *p);
struct node *find_node(int d);
void ins_node(struct node *p);
struct node *make_node(int d);
void print_node_list(struct node *p);

struct node *head, *tail;

void clean_up(struct node *node_ptr)
{
    struct node *prev_node;

    while(node_ptr != tail) {
        prev_node = node_ptr;
        node_ptr = node_ptr->next;
        del_node(prev_node);
    }
    del_node(tail);
}

void del_node(struct node *p)
{
    p->next->prev = p->prev;
    p->prev->next = p->next;
    free(p);
}

struct node *find_node(int d)
{
    struct node *node_ptr;

    node_ptr = head->next;
    while(node_ptr->data != d)
        node_ptr = node_ptr->next;

    if (node_ptr == tail) {
        fprintf(stderr, "node not found");
        return NULL;
    }

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

void print_list(struct node *p)
{
  // assumes head is passed to print_list
  p = p->next;
  while (p != tail) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int main(void)
{
    struct node *p;
    
    head = malloc(sizeof(*head));
    tail = malloc(sizeof(*tail));

    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
    
    // create list
    for (int i = 0; i < 10; i++) {
        p = make_node(i);
        insert(p);
    }
    
    print_list(head);
    
    // delete one
    struct node *to_del = find_node(3);
    if (to_del != NULL)
      del_node(to_del);
    
    print_list(head);
}
