// NOTE: every once in a while, this program gets stuck in execution...
// just execute it again if this occurs...

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void) {
    char walk[10][10];
    generate_random_walk(walk);
    print_array(walk);
    return 0;
}

void generate_random_walk(char walk[10][10]) {
    const char steps[] = {'B','C','D','E','F','G',
                          'H','I','J','K','L','M','N',
                          'O','P','Q','R','S','T','U',
                          'V','W','X','Y','Z'};
    int step; //indicates direction of a step
    int x = 0, y = 0; //coordinates of a step
    int i, j;
    bool no_step = false;

    // initialize matrix
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++)
            walk[i][j] = '.';
    }

    // seed sequence of pseudo-random numbers
    srand(time(NULL));

    // take steps
    walk[0][0] = 'A'; //first step
    i = 0;
    for (;;) {
        if (i >= 25)
            break;

        step = rand() % 4;

        // check for no_step at each case
        if (x == 0 && y == 0) {
            if (walk[1][0] != '.' && walk[0][1] != '.')
                no_step = true;
        }
        else if (x == 9 && y == 9) {
            if (walk[8][9] != '.' && walk[9][8] != '.')
                no_step = true;
        }
        else if (x == 0 && y == 9) {
            if (walk[0][8] != '.' && walk[1][9] != '.')
                no_step = true;
        }
        else if (x == 9 && y == 0) { 
            if (walk[9][1] != '.' && walk[8][0] != '.')
                no_step = true;
        }
        else {
            if (walk[x-1][y] != '.' && walk[x+1][y] != '.'
                    && walk[x][y+1] != '.' && walk[x][y-1] != '.')
                no_step = true;
        };

        if (no_step)
            break;

        // take step
        switch (step) {
            case 0:  //up
                if (y == 0)
                    break;
                else if (walk[x][y-1] != '.')
                    break;
                else {
                    y--;
                    walk[x][y] = steps[i];
                    i++;
                }; break;
            case 1:  //down
                if (y == 9)
                    break;
                else if (walk[x][y+1] != '.')
                    break;
                else {
                    y++;
                    walk[x][y] = steps[i];
                    i++;
                }; break;
            case 2: //left
                if (x == 0)
                    break;
                else if (walk[x-1][y] != '.')
                    break;
                else {
                    x--;
                    walk[x][y] = steps[i];
                    i++;
                }; break; 
            case 3: //right
                if (x == 9)
                    break;
                else if (walk[x+1][y] != '.')
                    break;
                else {
                    x++;
                    walk[x][y] = steps[i];
                    i++;
                }; break; 
            default: break;
        }
    }
}

void print_array(char walk[10][10]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", walk[i][j]);
        }
        printf("\n");
    }
}
