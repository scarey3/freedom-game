/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * Freedom Game. An "n-in-a-row" board game.
 */

#include <stdio.h>
#include "freedomMoves.h"
#include "freedomScoring.h"

#define ROWS 10
#define COLUMNS 10

void clearBoard(char board[][COLUMNS]);
void printBoard(char board[][COLUMNS]);

int main(void) {
    char boardArray[ROWS][COLUMNS];
    
    clearBoard(boardArray);
    printBoard(boardArray);
    
    return 0;
}

void clearBoard(char board[][COLUMNS]) {
    int i = 0;
    int j = 0;
    
    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLUMNS; j++)
            board[i][j] = ' ';
}

// Function prints the board.
void printBoard(char board[][COLUMNS]) {
    int i = 0;
    int j = 0;
    
    printf("  ");
    for(i = 0; i < COLUMNS; i++){
        printf(" [%c]", i + 65);
    }
    
    for(i = 0; i < ROWS; i++) {
        printf("\n[%d] ", i);
        for(j = 0; j < COLUMNS; j++)
            printf("%c   ", board[i][j]);
        printf("\n");
    }
}
