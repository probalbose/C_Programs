// char count & word count
// increment char count with each char read in except for ' ' and '\n'
// increment word count at each ' ' and '\n'

/* calculate average # of words in a sentence */

#include <stdio.h>

int main(void) {
    int char_count=0, word_count=0;
    char input;

    printf("enter a sentence: ");
    while ((input = getchar()) != '\n') {
        if (input == ' ')
            word_count++;
        else
            char_count++;
    }
    
    word_count++; // catch last word

    printf("Average word length: %.1f\n", (float) char_count / word_count);

    return 0;
}
