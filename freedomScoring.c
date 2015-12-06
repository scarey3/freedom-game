/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * Scoring functions for Freedom board game.
 */

#include "freedomScoring.h"

// Checks each column for 4 of the same char in a row.
void checkVertical(char **board, int **live, int size) {
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
                        live[i-k][j] = 5;
                    } 
                }
                count = 0;
            }
        }
    }
}

// Checks each row for 4 of the same char in a row.
void checkHorizontal(char **board, int **live, int size) {
    int count = 0;
    char value;
    
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
                    for(k = 1; k < 5; k++) {
                        live[i][j-k] = 5;
                    } 
                }
                count = 0;
            }
        }
    }
}

// Checks diagonally in both directions for 4 chars in a row.
void checkDiagonal(char **board, int **live, int size) {
    
}
