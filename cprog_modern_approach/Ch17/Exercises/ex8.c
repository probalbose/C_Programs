/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stack1.c (Chapter 19, page 488) */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

struct node {
    int val;
    struct node *next;
};

struct node *top= NULL;

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void make_empty(void)
{
    struct node *temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

bool is_empty(void)
{
    return top == NULL;
}

bool push(int i)
{
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL)
        return false;
    // insert node
    new->val = i;
    new->next = top;
    top = new;
    return true;
}

int pop(void)
{
  int ret;
  struct node *p;

  if (is_empty())
    terminate("Error in pop: stack is empty.");
  
  ret = top->val;
  p = top;
  top = top->next;
  free(p);
  return ret;
}
