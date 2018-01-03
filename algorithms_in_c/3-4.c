/*
 * =====================================================================================
 *
 *       Filename:  3-4.c
 *
 *    Description:  write a program to solve the Josephus problem, using an array 
 *                  instead of a linked list
 *
 *        Version:  1.0
 *        Created:  01/03/2018 03:28:13 AM
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

#define N 10

void init_arr(void);             // initialize the array with N members
void execute(int n);  // execute the nth member starting and index start
int  len_arr(void);              // return the length of the array
void reorder_arr(void);          // reorder the array such that the member at index n is removed
void print_arr(void);
void terminate(const char *msg);

static int arr[N];
static int len = N, start = 0;

int main(void) 
{
    // init array
    init_arr();

    while (len_arr() > 1) {
        print_arr();

        // execute one
        execute(5);

        // rebuild array
        reorder_arr();
    }
    
    // print remaining member
    print_arr();

    return 0;
}

void init_arr(void)
{
    for (int i = 0; i < N; i++)
        arr[i] = i;
}

void execute(int n)
{
    int i;
    i = (start + n-1) % len;
    arr[i] = -1;
    start = i;
}

int len_arr(void)
{
    return len;
}

void reorder_arr(void)
{
    int i;

    // find index with value == 0
    for (i = 0; i < len && arr[i] != -1; i++)
        ;
    // copy i+1 into i until i == len
    for (i++; i < len; i++)
        arr[i-1] = arr[i];
    // decrement len
    len--;
}

void print_arr(void)
{
    printf("len: %d\n", len);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
