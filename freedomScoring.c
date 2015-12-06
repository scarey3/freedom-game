/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * 
 */

#include "freedomScoring.h"

// Called in main. Calculates and displays the scores.
void score(char **board, int size) {
    int blackScore = 0;
    int whiteScore = 0;
    int **state = allocateStateArray(size);
    
    int i = 0;
    int j = 0;
    
    checkVertical(board, state, size);
    checkHorizontal(board, state, size);
    // checkDiagonal(board, state, size);
    
    // Adds up the score from the state array.
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            if(state[i][j] == 1)
                blackScore++;
            if(state[i][j] == 2)
                whiteScore++;
    
    // Prints game results.
    if(blackScore > whiteScore) {
        printf("Black wins %d-%d.", blackScore, whiteScore);
    }
    if(blackScore < whiteScore) {
        printf("White wins %d-%d.", whiteScore, blackScore);
    }
    else {
        printf("Tie %d-%d.", blackScore, whiteScore);
    }
}

// Creates the state array
int **allocateStateArray(int size) {
    int i = 0;
    int **state = (int**)malloc(size * sizeof(int*));
    for(i = 0; i < size; i++) {
        state[i] = (int*)malloc(size * sizeof(int));
    }
    return state;
}

// Checks each row for 4 of the same char in a row.
void checkVertical(char **board, int **state, int size) {
    int count = 0;
    char value;
    
    int i = 0;
    int j = 0;
    int k = 0;

    for(j = 0; j < size; j++) {
        count = 0;
        for(i = 0; i < size; i++) {
            value = board[i - count][j];
            
            if(board[i][j] == value) {
                count++;
            }
            else {
                if(count == 4) {
                    for(k = 1; k < 5; k++) {
                        state[i-k][j] = 5;
                    } 
                }
                count = 0;
            }
        }
    }
}

// Checks each row for 4 of the same char in a row.
void checkHorizontal(char **board, int **state, int size) {
    int count = 0;
    char value;
    char p1 = 'B';
    char p2 = 'W';
    
    int i = 0;
    int j = 0;
    int k = 0;

    for(i = 0; i < size; i++) {
        count = 0;
        for(j = 0; j < size; j++) {
            value = board[i][j - count];
            
            if(board[i][j] == value) {
                count++;
            }
            else {
                if(count == 4) {
                    if(value == p1)
                        for(k = 1; k < 5; k++)
                            state[i][j-k] = 1;
                    if(value == p2)
                        for(k = 1; k < 5; k++)
                            state[i][j-k] = 1;
                }
                count = 0;
            }
        }
    }
}

// Checks diagonally in both directions for 4 chars in a row.
void checkDiagonal(char **board, int **state, int size) {
    
}
