#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *create_array(int n, int initial_value);

int main(void) {
    int len, initv, *arr;
    printf("enter length of array: ");
    scanf("%d", &len);
    printf("enter init value of members: ");
    scanf("%d", &initv);
    arr = create_array(len, initv);

    for (int i = 0; i < len; i++)
        printf("| %d |", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}

int *create_array(int n, int initial_value) {
    int *ret = malloc(n * sizeof(int));
    if (ret != NULL)
        for (int i = 0; i < n; i++)
            ret[i] = initial_value;
    return ret;
}
