/* Write a program that counts the number of vowels (a,e,i,o,u) in a sentence */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 99

int compute_vowel_count(const char *sentence);

int main(void) {
    char input[BUFSIZE+1];

    printf("Enter a sentence: ");
    scanf(" %s", input);
    printf("# of vowels: %d\n", compute_vowel_count(input));

    return 0;
}

int compute_vowel_count(const char *sentence) {
    int count = 0;
    char tmp;
    // iterate over word
    for (; *sentence; sentence++) {
        tmp = toupper(*sentence);
        // check value of current char
        if (tmp == 'A' || tmp == 'E' || tmp == 'I' || tmp == 'O' || tmp == 'U')
            // if vowel, inc count
            count++;
    }

    return count;
}
