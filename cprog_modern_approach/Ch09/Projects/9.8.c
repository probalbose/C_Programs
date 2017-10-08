#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);

int main(void) {
    char choice;
    int wins=0, losses=0;
    bool outcome;

    printf("play game? ");
    scanf("%c", &choice);
    choice = toupper(choice);
    if (choice == 'Y') {
        srand(time(NULL));
        for(;;) {
            outcome = play_game();
            if (outcome == true) {
                printf("you win!\n");
                wins++;
            }
            else {
                printf("you lose!\n");
                losses++;
            }
            printf("play again? ");
            scanf(" %c", &choice);
            if (toupper(choice) != 'Y')
                break;
        }
    }
    printf("Wins: %d  Losses: %d\n", wins, losses);
    printf("exiting...\n");
    return 0;
}

int roll_dice(void) {
    int die1, die2;
    die1 = (rand() % 6) + 1;
    die2 = (rand() % 6) + 1;
    return die1 + die2;
}

bool play_game(void) {
    int result, point;

    result = roll_dice();
    printf("you rolled: %d\n", result);

    if (result==2 || result==3 || result==12)
        return false;
    else if (result == 7 || result == 11)
        return true;

    point = result;
    printf("your point is: %d\n", point);

    for(;;) {
        result = roll_dice();
        printf("you rolled: %d\n", result);
        if (result == 7)
            return false;
        else if (result == point)
            return true;
        else 
            continue;
    }
}
