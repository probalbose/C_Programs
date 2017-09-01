/* 
 * selection sort
 */

#include <stdio.h>

#define SIZE 5 

void selection_sort(int a[], int n);

int main(void) {
    int a[SIZE], i;

    printf("enter %d integers:", SIZE);
    for (i = 0; i < SIZE; i++)
        scanf(" %d", &a[i]);

    printf("unsorted array: ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", a[i]);
    printf("\n");

    selection_sort(a, SIZE);

    printf("sorted array: ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void selection_sort(int a[], int n) {
    int i, largest=0, swap_index=n-1;
    // base case
    if (n == 1)
        return;
    else {
        for (i = 0; i < n; i++) {
           if (a[i] > largest) {
               largest = a[i];
               swap_index = i;
           }
        }
        // swap largest with element at end of array
        a[swap_index] = a[n-1];
        a[n-1] = largest;
        
        selection_sort(a, n-1);
    }
}












    
