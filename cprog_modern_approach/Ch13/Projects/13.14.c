#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 20

bool are_anagrams(const char *word1, const char *word2);

int main(void) {
    char word1[BUFSIZE+1], word2[BUFSIZE+1];

    printf("enter first word: ");
    scanf(" %s", word1);
    printf("enter second word: ");
    scanf(" %s", word2);

    if (are_anagrams(word1, word2))
        printf("the words are anagrams\n");
    else
        printf("the words are not anagrams\n");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2) {
    int letters[26] = {0};
    
    // count char frequencies
    for (int i = 0; i < strlen(word1); i++) {
        if (isalpha(word1[i]))
            letters[tolower(word1[i]) - 'a']++;
    }
    
    // dec char frequencies
    for (int i = 0; i < strlen(word2); i++) {
        if (isalpha(word2[i]))
            letters[tolower(word2[i]) - 'a']--;
    }

    for (int i = 0; i < 26; i++)
        if (letters[i] != 0) {
            return false;
        }

    return true;
}
