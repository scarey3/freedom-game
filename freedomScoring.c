/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * Scoring functions for Freedom board game.
 */

#include "freedomScoring.h"

/*
void checkVertical(char board[][COLUMNS], int live[][COLUMNS]) {
    int count = 0;
    char value;
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    for(i = 0; i < COLUMNS; i++) {
        count = 0;
        
        for(j = 0; j < ROWS; j++) {
            if(count == 0) {
                value = board[j][i];
                count++;
            }
        
            if(count > 0 && count < 4 && board[i][j] == value) {
                count++;
            }
            else if((j == ROWS - 1 || board[i][j+1] != value) && count == 4) {
                for(k = 0; k < 4; k++)
                    live[i][j-k] = 1;
            }
        }
    }
} */

void checkVertical(char **board, int **live, int col, int row, int count) {
    if(col > COLUMNS)
        return;
    if(count < 5 && (board[row+1][col+1] != board[row][col] || row == ROWS))
        int i = 0;
        int j = 0;
        for(i = 0; i < 4; i++)
            live[row - i][col];
        
}

void checkHorizontal(char board[][COLUMNS], int live[][COLUMNS]) {

}

void checkDiagonal(char board[][COLUMNS], int live[][COLUMNS]) {

}
