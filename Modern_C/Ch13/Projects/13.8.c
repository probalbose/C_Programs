/* Compute the Scrabble value of a word */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 99

int compute_scrabble_value(const char *word);

int main(void) {
    char buf[BUFSIZE+1]={0};

    printf("Enter a word: ");
    scanf(" %s", buf);
    printf("Scrabble value: %d\n", compute_scrabble_value(buf));

    return 0;
}

int compute_scrabble_value(const char *word) {
    int value = 0, sum = 0;

    while (*word) {
        value = 0;
        switch (toupper(*word)) {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                value = 1; break;
            case 'D':
            case 'G':
                value = 2; break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                value = 3; break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                value = 4; break;
            case 'K':
                value = 5; break;
            case 'J':
            case 'X':
                value = 8; break;
            case 'Q':
            case 'Z':
                value = 10; break;
            default:
                printf("%c is not a valid character.\n", *word); break;
        }
        sum += value;
        word++;
    }
    return sum;
}
