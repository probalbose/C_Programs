/*
 * Write functions that, given an array a and its length n, return:
 * 1) a's largest element
 * 2) the average of all elements in a
 * 3) the number of positive elements in a
 */

#include <stdio.h>

int largest(int array[], int length);
int average(int array[], int length);
int num_pos(int array[], int length);

int main(void) {
    int n, i;
    printf("enter the length of the array: ");
    scanf("%d", &n);

    int a[n];

    printf("enter the integer elements of the array separated by spaces: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("largest element in the array: %d\n", largest(a, n));
    printf("average of elements in a: %d\n", average(a, n));
    printf("number of positive elements in a: %d\n", num_pos(a, n));

    return 0;
}

int largest(int array[], int length) {
    int largest = 0, i;
    for (i = 0; i < length; i++) {
        if (array[i] > largest)
            largest = array[i];
    }
    return largest;
}

int average(int array[], int length) {
    int average=0, i;
    for (i = 0; i < length; i++)
        average += array[i];
    return average / length;
}

int num_pos(int array[], int length) {
    int num_pos=0, i;
    for (i = 0; i < length; i++) {
        if (array[i] > 0)
            num_pos++;
    }
    return num_pos;
}
