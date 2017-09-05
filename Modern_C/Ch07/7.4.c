/*
    Write a program that translates an alphabetic phone number into 
    numeric form.
*/

#include <stdio.h>
#include <ctype.h> // toupper()

int main(void) {
    char input;

    printf("enter phone number: ");

    while ((input = getchar()) != '\n') {
        input = toupper(input);
        switch (input) {
            case 'A': case 'B': case 'C':
                printf("2");
                break;
            case 'D': case 'E': case 'F':
                printf("3");
                break;
            case 'G': case 'H': case 'I':
                printf("4");
                break;
            case 'J': case 'K': case 'L':
                printf("5");
                break;
            case 'M': case 'N': case 'O':
                printf("6");
                break;
            case 'P': case 'R': case 'S':
                printf("7");
                break;
            case 'T': case 'U': case 'V':
                printf("8");
                break;
            case 'W': case 'X': case 'Y':
                printf("9");
                break;
            default:
                printf("%c", input);
                break;
        }
    }

    printf("\n");
    return 0;
}
