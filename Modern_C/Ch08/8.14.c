/* 
 * Write a program that reverses the words in a sentence. 
 */

#include <stdio.h>
#include <string.h>

#define SIZE 100  // Array size

int main(void) {
    char sentence[SIZE];
    char rev_sentence[SIZE];
    char term_char=0, c, start_of_word=0;
    int i, j;

    printf("enter a sentence: ");
    for (i = 0; ; i++) {
        c = getchar();
        if (c == '?' || c == '.' || c == '!') {
            term_char = c;
        } else
            sentence[i] = c;

        if (term_char)
            break;
    }
    // reverse the string
    for (i = (strlen(sentence) - 1), j = 0; i >= 0; i--, j++)
        rev_sentence[j] = sentence[i];

    // reverse the reversed words
    for (i = 0; i < strlen(rev_sentence); i++) {
        if (rev_sentence[i] == ' ') {
            for (j = i; j >= start_of_word; j--)
                printf("%c", rev_sentence[j]);
            start_of_word = i + 1;
        }
    }

    printf("%c\n", term_char);

    return 0;
}
