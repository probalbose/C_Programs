/* 
 * Biff filter
 */

#include <stdio.h>
#include <ctype.h>

#define ARRAY_LENGTH 100

int main(void) {
    char input, sentence[ARRAY_LENGTH];
    int i,j;

    printf("Enter a sentence: ");
    for (i = 0; (input = getchar()) != '\n'; i++)
        sentence[i] = toupper(input);
    
    printf("Translation: ");
    for (j = 0; j < i; j++) {
        switch (sentence[j]) {
            case 'A':   printf("4"); break;
            case 'B':   printf("8"); break;
            case 'E':   printf("3"); break;
            case 'I':   printf("1"); break;
            case 'O':   printf("0"); break;
            case 'S':   printf("5"); break;
            default:    printf("%c", sentence[j]); break;
        }
    }

    printf("!!!!!\n");

    return 0;
}
