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
void clearStateArray(int array[][COLUMNS]);
void printBoard(char board[][COLUMNS]);

int main(void) {
    char boardArray[ROWS][COLUMNS];
    int stateArray[ROWS][COLUMNS];
    
    int i = 0;
    int j = 0;
    
    clearBoard(boardArray);
    clearStateArray(stateArray);
    
    checkVertical(boardArray, stateArray, 0 , 0, 0);
    
    printBoard(boardArray);
    
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++)
            printf("%d ", stateArray[i][j]);
        printf("\n");
    }
    
    return 0;
}

// Clear the game board.
void clearBoard(char board[][COLUMNS]) {
    int i = 0;
    int j = 0;
    
    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLUMNS; j++)
            board[i][j] = ' ';
}

// Clear the state array.
void clearStateArray(int array[][COLUMNS]) {
    int i = 0;
    int j = 0;
    
    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLUMNS; j++)
            array[i][j] = 0;
}

// Function prints the game board.
void printBoard(char board[][COLUMNS]) {
    int i = 0;
    int j = 0;

    printf("  ");

    for(i = 0; i < COLUMNS; i++){
        printf("\e[4m %c\e[0m", i + 65);
    }
    
    printf("\n");
    
    for(i = 0; i < ROWS; i++) {
        printf("%d| ", i);
        for(j = 0; j < COLUMNS; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}
