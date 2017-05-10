// Read an integer and display it in octal

#include <stdio.h>

int main(void)
{
    int i=0, j=0, k=0, l=0 , m=0;
    int num;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &num);

    i = num % 8;
    num /= 8;
    j = num % 8;
    num /= 8;
    k = num % 8;
    num /= 8;
    l = num % 8;
    num /= 8;
    m = num % 8;
    num /= 8;

    printf("Your number in octal: %d%d%d%d%d\n", m, l, k, j, i);
    return 0;
}
