#include <stdio.h>

int check(int x, int y, int n);

int main(void) {
    int x, y, n;
    printf("enter x, y, and n separated by spaces: ");
    scanf("%d %d %d", &x, &y, &n);
    printf("%d\n", check(x, y, n));
    return 0;
}

int check(int x, int y, int n) {
    if (x < 0 || y < 0)
        return 0;
    else if (x > n - 1 || y > n - 1)
        return 0;
    else
        return 1;
}
