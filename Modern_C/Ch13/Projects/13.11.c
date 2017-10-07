// char count & word count
// increment char count with each char read in except for ' ' and '\n'
// increment word count at each ' ' and '\n'

/* calculate average # of words in a sentence */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 99

double compute_average_word_length(const char *sentence);

int main(void) {
    char input, buf[BUFSIZE+1], *p = buf;

    printf("enter a sentence: ");
    while ((input = getchar()) != '\n') {
        if (input == '.' || input == '?' || input == '!' || input == ',')
            continue;
        else *p++ = input;
    }
    *p = '\0';

    printf("Average word length: %.1lf\n", compute_average_word_length(buf));

    return 0;
}

double compute_average_word_length(const char *sentence) {
    int char_count=0, word_count=0;
    double avg_length;

    for (; *sentence; sentence++) {
        if (*sentence == ' ')
            word_count++;
        else
            char_count++;
    }
    
    word_count++; // catch last word

    avg_length = (double) char_count / word_count;

    return avg_length;
}
