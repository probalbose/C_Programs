#include <ctype.h>
#include <stdio.h>

#define SIZE 80

int main(void) {
    char arr[SIZE] = {0}, *p, *q;

    printf("enter a sentence: ");
    p = arr;
    while (*p != '\n') {
        *p = getchar();
        *p = tolower(*p);
        if (p > arr + SIZE)
            break;
        else if (*p >= 'a' && *p <= 'z')
            p++;
        else
            continue;
    }

    p--; // dodge the '\n' at the end of arr
    q = arr;
    while (p > q) {
        if (*p != *q) {
            printf("not a palindrome\n");
            return 0;
        }
        else {
            p--;
            q++;
        }
    }

    printf("palindrome\n");
    return 0;
}
