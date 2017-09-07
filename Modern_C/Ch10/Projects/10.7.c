/*
 * Prompt the user for a number and display it using characters to
 * simulate the effect of a seven-segment display
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10

/* external variables */
const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, //0
                             {0, 1, 1, 0, 0, 0, 0}, //1
                             {1, 1, 0, 1, 1, 0, 1}, //2
                             {1, 1, 1, 1, 0, 0, 1}, //3...
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};
int digits[4][MAX_DIGITS * 4];

/* prototype */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void) {
    char input;
    int num_digits = 0;

    clear_digits_array();

    printf("enter a number: ");
    for(;;) {
        scanf("%c", &input);
        if (input == '\n')
            break;

        if (num_digits < MAX_DIGITS && input >= '0' && input <= '9') {
            process_digit(input - '0', num_digits * 4);
            num_digits++;
        }
    }

    print_digits_array();
        
    return 0;
}

void clear_digits_array(void) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < MAX_DIGITS * 4; j++)
            digits[i][j] = ' ';
    }
}

void process_digit(int digit, int position) {
    int i;

    for (i = 0; i < 7; i++) {
        if (segments[digit][i] == 1) {
            switch (i) {
                case 0:     digits[0][position+1] = '_';
                            break;
                case 1:     digits[1][position+2] = '|';
                            break;
                case 2:     digits[2][position+2] = '|';
                            break;
                case 3:     digits[2][position+1] = '_';
                            break;
                case 4:     digits[2][position] = '|';
                            break;
                case 5:     digits[1][position] = '|';
                            break;
                case 6:     digits[1][position+1] = '_';
                            break;
                default:    break;
            }
        }
    }
}

void print_digits_array(void) {
    int i, j;
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < MAX_DIGITS * 4; j++)
            printf("%c", digits[i][j]);
        printf("\n");
    }
}
