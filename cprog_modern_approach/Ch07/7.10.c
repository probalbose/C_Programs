/* Write a program that counts the number of vowels (a,e,i,o,u) in a sentence */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int count = 0;
    char input;

    printf("Enter a sentence: ");
    while ((input = getchar()) != '\n') {
        input = toupper(input);
        switch (input) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
                count++;
                break;
            default:
                break;
        }
    }
    printf("# of vowels: %d\n", count);

    return 0;
}
