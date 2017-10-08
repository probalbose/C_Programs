#include <stdio.h>

int count_spaces(const char *s);

int main(void) {
    const char buf[] = "The quick brown fox jumped over the lazy dog.";
    printf("Spaces: %d\n", count_spaces(buf));
    return 0;
}

int count_spaces(const char *s) {
    int count = 0;

    while (*s)
        if (*s++ == ' ')
            count++;
    return count;
}
