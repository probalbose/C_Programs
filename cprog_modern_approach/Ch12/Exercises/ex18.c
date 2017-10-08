#include <stdio.h>

int evaluate_position(char *chess_board);

int main(void) {
    int result;
    // initialize board
    char chess_board[8][8] = {{'R', 'N', 'B', '.', 'K', 'B', 'N', 'R'},
                              {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                              {'r', '.', 'b', 'q', 'k', 'b', 'n', 'r'}};

    result = evaluate_position(chess_board[0]);
    if (result > 0)
        printf("white has the advantage\n");
    else if (result < 0)
        printf("black has the advantage\n");
    else
        printf("neither side has the advantage\n");
    return 0;
}

int evaluate_position(char *board) {
    int black = 0, white = 0;
    char *p;
    for (p = board; p < board + 8*8; p++) {
        switch (*p) {
            case 'Q': white += 9; break;
            case 'R': white += 5; break;
            case 'B': white += 3; break;
            case 'N': white += 3; break;
            case 'P': white++; break;
            case 'q': black += 9; break;
            case 'r': black += 5; break;
            case 'b': black += 3; break;
            case 'n': black += 3; break;
            case 'p': black++; break;
            default: break;
        }
    }
    return white - black;
}
