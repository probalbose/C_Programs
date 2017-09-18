/* 
 * Write a program that reverses the words in a sentence. 
 */

#include <stdio.h>
#include <string.h>

#define SIZE 100  // Array size

int main(void) {
    char sentence[SIZE] = {0}, rev_sentence[SIZE] = {0};
    char *p, *q, c, term_char='0';
    int start_of_word=0, len=0;

    printf("enter a sentence: ");
    for (p = sentence; p < sentence + SIZE; p++) {
        *p = getchar();
        len++;
        if (*p == '?' || *p == '.' || *p == '!') {
            term_char = *p;
            break;
        }
    }

    // reverse the string
    for (p--, q = rev_sentence; p >= sentence; p--, q++)
        *q = *p;

    // TODO reverse the reversed words
    for (p = rev_sentence + len; p >= rev_sentence; p--) {
        if (*p == ' ') {
            for (q = p+1; *q != ' ' && q < rev_sentence + len; q++)
                printf("%c", *q);
            printf(" ");
        }
    }

    for(p = rev_sentence; *p != ' '; p++)
        printf("%c", *p);

    printf("%c\n", term_char);

    return 0;
}
