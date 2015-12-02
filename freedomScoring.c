/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * Scoring functions for Freedom board game.
 */

#include "freedomScoring.h"

void checkVertical(char board[][COLUMNS], int live[][COLUMNS]) {
    int count = 0;
    char value;
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    for(i = 0; i < COLUMNS; i++) {
        count = 0;
        
        for(j = 0; j < ROWS; j++) {
            if(count >= 0 && count < 4)
                count++;
            else if(((count == 4) && (j == ROWS - 1)) || board[i][j+1] == value) {
                for(k = 0; k < 4; k++)
                    live[i][j-k] = 1;
            }
            
            if(!count) {
                value = board[i][j];
                count++;
            }
        }
    }
}

void checkHorizontal(char board[][COLUMNS], int live[][COLUMNS]) {

}

void checkDiagonal(char board[][COLUMNS], int live[][COLUMNS]) {

}
