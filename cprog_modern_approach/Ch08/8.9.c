//TODO: make first step occur in the top left corner every time

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void) {
    const char steps[] = {'B','C','D','E','F','G',
                          'H','I','J','K','L','M','N',
                          'O','P','Q','R','S','T','U',
                          'V','W','X','Y','Z'};
    char matrix[10][10];
    int step; //indicates direction of a step
    int x = 0, y = 0; //coordinates of a step
    int i, j;
    bool no_step = false;

    // initialize matrix
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++)
            matrix[i][j] = '.';
    }

    // seed sequence of pseudo-random numbers
    srand(time(NULL));

    // take steps
    matrix[0][0] = 'A'; //first step
    i = 0;
    for (;;) {
        if (i >= 25)
            break;

        step = rand() % 4;

        // check for no_step at each case
        if (x == 0 && y == 0) {
            if (matrix[1][0] != '.' && matrix[0][1] != '.')
                no_step = true;
        }
        else if (x == 9 && y == 9) {
            if (matrix[8][9] != '.' && matrix[9][8] != '.')
                no_step = true;
        }
        else if (x == 0 && y == 9) {
            if (matrix[0][8] != '.' && matrix[1][9] != '.')
                no_step = true;
        }
        else if (x == 9 && y == 0) { 
            if (matrix[9][1] != '.' && matrix[8][0] != '.')
                no_step = true;
        }
        else {
            if (matrix[x-1][y] != '.' && matrix[x+1][y] != '.'
                    && matrix[x][y+1] != '.' && matrix[x][y-1] != '.')
                no_step = true;
        };

        if (no_step)
            break;

        // take step
        switch (step) {
            case 0:  //up
                if (y == 0)
                    break;
                else if (matrix[x][y-1] != '.')
                    break;
                else {
                    y--;
                    matrix[x][y] = steps[i];
                    i++;
                }; break;
            case 1:  //down
                if (y == 9)
                    break;
                else if (matrix[x][y+1] != '.')
                    break;
                else {
                    y++;
                    matrix[x][y] = steps[i];
                    i++;
                }; break;
            case 2: //left
                if (x == 0)
                    break;
                else if (matrix[x-1][y] != '.')
                    break;
                else {
                    x--;
                    matrix[x][y] = steps[i];
                    i++;
                }; break; 
            case 3: //right
                if (x == 9)
                    break;
                else if (matrix[x+1][y] != '.')
                    break;
                else {
                    x++;
                    matrix[x][y] = steps[i];
                    i++;
                }; break; 
            default: break;
        }
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
