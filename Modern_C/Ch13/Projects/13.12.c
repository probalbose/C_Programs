/* 
 * Write a program that reverses the words in a sentence. 
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 20  // Array size

void reverse_string(char *str);

int main(void) {
    char sentence[30][BUFSIZE+1] = {0};
    char *p, *q, c, term_char;
    int start_of_word=0, len=0;

    printf("enter a sentence: ");
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j <= BUFSIZE; j++) {
            c = getchar();
            if (c == ' ' || c == '\n') {
                sentence[i][j] = '\0';
                break;
            }
            else if (c == '.' || c == '?' || c == '!')
                term_char = c;
            else
                sentence[i][j] = c;
        }
        
        if (c == '\n')
            break;
    }

    for (int i = 0; i < 30; i++)
        if (strlen(sentence[i]))
            reverse_string(sentence[i]);

    for (int i = 0; i < 30; i++)
        if (strlen(sentence[i]))
            printf(" %s", sentence[i]);

    printf("%c\n", term_char);

    return 0;
}

void reverse_string(char *str) {
    char *p, *q, tmp;

    p = str;
    q = str + strlen(str) - 1; // - '\0'

    for (; q > p; p++, q--) {
        tmp = *p;
        *p = *q;
        *q = tmp;
    }
}
