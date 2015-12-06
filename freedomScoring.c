/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * Scoring functions: A separate function is used to store the live tiles. A live
 *      tile is a tile that is part of a group of 4 consecutive like-tiles.
 *
 *      IE: 0 W 0 W 0 0 
 *          0 0 W W 0 0     This would be 7 points for white. If a tile is already
 *          0 0 0 W 0 0     live, it will not be scored twice.
 *          0 0 0 W W 0
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
    checkDiagonal(board, state, size);
    
    // Adds up the score from the state array.
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            if(state[i][j] == 1)
                blackScore++;
            else if(state[i][j] == 2)
                whiteScore++;

    // Prints game results.
    if(blackScore > whiteScore) {
        printf("\nBlack wins %d-%d.\n", blackScore, whiteScore);
    }
    else if(blackScore < whiteScore) {
        printf("\nWhite wins %d-%d.\n", whiteScore, blackScore);
    }
    else {
        printf("\nTie %d-%d.\n", blackScore, whiteScore);
    }
}

// Creates the state array
int **allocateStateArray(int size) {
    int i = 0;
    int j = 0;
    int **state = (int**)malloc(size * sizeof(int*));
    for(i = 0; i < size; i++) {
        state[i] = (int*)malloc(size * sizeof(int));
    }
    
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            state[i][j] = 0;
    
    return state;
}

// Checks each row for 4 of the same char in a row.
void checkVertical(char **board, int **state, int size) {
    int count = 0;
    char value;
    char p1 = 'B';
    char p2 = 'W';
    int stateValue = 0;
    
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
                    if(value == p1)
                        stateValue = 1;
                    else
                        stateValue = 2;
                    for(k = 1; k < 5; k++)
                        state[i-k][j] = stateValue;
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
    int stateValue = 0;
    
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
                        stateValue = 1;
                    else
                        stateValue = 2;
                    for(k = 1; k < 5; k++)
                        state[i][j-k] = stateValue;
                }
                count = 0;
            }
        }
    }
}

// Checks diagonally in both directions for 4 chars in a row.
void checkDiagonal(char **board, int **state, int size) {
    int count = 0;
    char value;
    int last = 0;
    char p1 = 'B';
    char p2 = 'W';
    int stateValue = 0;
    int row = 0;
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    // Pass 1 starts from top-left.
    for(i = 3; i < size; i++) {
        count = 0;
        for(j = 0; i-j >= 0; j++) {
            row = i - j;
            if(count == 0) {
                value = board[row][j];
                count++;
            }
            else if(board[row][j] == value)
                count++;
            else {
                value = board[row][j];
                count = 1;
            }
            if(count == 4 && row > 0) {
                if(board[row-1][j+1] != value) {
                    if(value == p1)
                        stateValue = 1;
                    else
                        stateValue = 2;
                    for(k = 0; k < 4; k++)
                        state[row+k][j-k] = stateValue;
                    count = 0;
                }
            }
            else if(count == 4 && row == 0) {
                if(value == p1)
                        stateValue = 1;
                    else
                        stateValue = 2;
                    for(k = 0; k < 4; k++)
                        state[row+k][j-k] = stateValue;
                count = 0;
            }   
        }
    }
    
    // Pass 2 starts from bottom-left.
    for(i = size - 4; i >= 0; i--) {
        count = 0;
        for(j = 0; i+j < size; j++) {
            row = i + j;
            if(count == 0) {
                value = board[row][j];
                count++;
            }
            else if(board[row][j] == value)
                count++;
            else {
                value = board[row][j];
                count = 1;
            }
            if(count == 4 && row < size-1) {
                if(board[row+1][j+1] != value) {
                    if(value == p1)
                        stateValue = 1;
                    else
                        stateValue = 2;
                    for(k = 0; k < 4; k++)
                        state[row-k][j-k] = stateValue;
                    count = 0;
                }
            }
            else if(count == 4 && row == size-1) {
                if(value == p1)
                        stateValue = 1;
                    else
                        stateValue = 2;
                    for(k = 0; k < 4; k++)
                        state[row-k][j-k] = stateValue;
                count = 0;
            }   
        }
    }
    
    // Pass 3 starts from top-right.
    for(i = 3; i < size; i++) {
        count = 0;
        for(j = size - 1; i-((size-1)-j) >= 0; j--) {
            row = i-((size-1)-j);
            if(count == 0) {
                value = board[row][j];
                count++;
            }
            else if(board[row][j] == value)
                count++;
            else {
                value = board[row][j];
                count = 1;
            }
            if(count == 4 && row > 0) {
                if(board[row-1][j-1] != value) {
                    if(value == p1)
                        stateValue = 1;
                    else
                        stateValue = 2;
                    for(k = 0; k < 4; k++)
                        state[row+k][j+k] = stateValue;
                    count = 0;
                }
            }
            else if(count == 4 && row == 0) {
                if(value == p1)
                        stateValue = 1;
                    else
                        stateValue = 2;
                    for(k = 0; k < 4; k++)
                        state[row+k][j+k] = stateValue;
                count = 0;
            }   
        }
    }
    
    // Pass 4 starts from bottom-right.
    for(i = size - 4; i >= 0; i--) {
        count = 0;
        for(j = size - 1; i+(size-1)-j < size; j--) {
            row = i+(size-1)-j;
            if(count == 0) {
                value = board[row][j];
                count++;
            }
            else if(board[row][j] == value)
                count++;
            else {
                value = board[row][j];
                count = 1;
            }
            if(count == 4 && row < size-1) {
                if(board[row-1][j+1] != value) {
                    if(value == p1)
                        stateValue = 1;
                    else
                        stateValue = 2;
                    for(k = 0; k < 4; k++)
                        state[row-k][j+k] = stateValue;
                    count = 0;
                }
            }
            else if(count == 4 && row == size-1) {
                if(value == p1)
                        stateValue = 1;
                    else
                        stateValue = 2;
                    for(k = 0; k < 4; k++)
                        state[row-k][j+k] = stateValue;
                count = 0;
            }   
        }
    }
}
