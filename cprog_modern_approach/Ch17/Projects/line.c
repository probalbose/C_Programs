/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* line.c (Chapter 15, page 364) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

#ifndef MAX_WORD_LEN
#define MAX_WORD_LEN 20
#endif

//char line[MAX_LINE_LEN+1];
struct line {
    char word[MAX_WORD_LEN];
    struct line *next_word;
};

struct line *front = NULL, *back = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  struct line *p;
  // traverse list, freeing each previous node
  while (num_words > 0) {
      for (p = front; p->next_word != NULL; p=p->next_word)
          ;
      free(p);
      num_words -= 1;
  }
  front = NULL;
  back = NULL;
  line_len = 0;
  
  //line[0] = '\0';
}

void add_word(const char *word)
{
  // alloc new node, add word + ' '
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, i, j;

  extra_spaces = MAX_LINE_LEN - line_len;
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ')
      putchar(line[i]);
    else {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
}

void flush_line(void)
{
  if (line_len > 0)
    puts(line);
}
