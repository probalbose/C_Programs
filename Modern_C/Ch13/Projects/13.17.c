#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define SIZE 80

bool is_pal(const char *message);

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
    *p = '\0';

    if (is_pal(arr))
        printf("palindrome\n");
    else
        printf("not a palindrome\n");

    return 0;
}

bool is_pal(const char *msg) {
    const char *p;
    p = msg + strlen(msg) - 1;
    for (; msg < p; msg++, p--)
        if (*msg != *p)
            return false;
    return true;
}
