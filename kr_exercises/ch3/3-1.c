/* binsearch() -- make only 1 test inside the while loop instead of 2
 *
 * Constants
 *
 * Changing Data
 * - low
 * - high
 * - mid
 * - int v[]
 *   - sorted array passed to binsearch
 * - x
 *   - value binsearch is looking for in v
 * - n
 *   - length of v
 *
 * Outline
 * - main() calls binsearch(x,v,n)
 *   - prints value returned by binsearch
 * - binsearch()
 *   - int, int array, int -> int
 *   - binsearch(5,[1,2,3,4,6,8,9],7) = -1
 *   - binsearch(43,[4,6,9,43,98],5) = 43
 *
 */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void)
{
    int x, i;
    int n = 1000;
    int v[n];
    int result;

    // initialize v[]
    for (i = 0; i < 1000; ++i)
        v[i] = i;

    x = 3000;
    result = binsearch(x, v, n);
    printf("binsearch returned %d\n", result);
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int result = -1;
    int low = 0;
    int high = n - 1;
    int mid = (high + low) / 2;

    while ((low <= high) && (v[mid] != x))
    {
        mid = (high + low) / 2;
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    // if x was found, update result
    if (v[mid] == x)
        result = mid;
    return result;
}

