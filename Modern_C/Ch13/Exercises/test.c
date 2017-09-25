#include <stdio.h>

int main(int argc, char *argv[]) {
    int i, j;
    char s[100];

    printf("enter '12abc34 56def78': ");
    scanf("%d%s%d", &i, s, &j);
    printf("i: %d\n", i);
    printf("s: %s\n", s);
    printf("j: %d\n", j);

    return 0;
}
