/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * Freedom Game. An "n-in-a-row" board game.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freedomMoves.h"
#include "freedomScoring.h"

#define MAX_BUF 1024
#define MIN_SIZE 10
#define MAX_SIZE 26

void clearBoard(char **board, int size);
void clearStateArray(int **state, int size);
void printBoard(char **board, int size);
char** allocateBoard(int size);
int** allocateStateArray(int size);
void freeBoard(char **board, int size);
int getSize();

int main(void) {
    char **board;
    int **state;
    
    int size = getSize();
    
    int i = 0;
    int j = 0;
    
    board = allocateBoard(size);
    state = allocateStateArray(size);
    
    clearBoard(board, size);
    clearStateArray(state, size);
    
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            board[i][j] = 'W';
    
    //printBoard(board, size);
    
    checkDiagonal(board, state, size);
    
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++)
            printf("%d ", state[i][j]);
        printf("\n");
    }
    
    return 0;
}

//Gets board size from user
int getSize(){
    char buffer[MAX_BUF];
    int size = 0;
    printf("Please enter the size of the board:\n");
    while(1){
        fgets(buffer, MAX_BUF-1, stdin);
        buffer[strlen(buffer)-1] = '\0';
        size = atoi(buffer);
        if(size < MIN_SIZE || size > MAX_SIZE){
            printf("\"%s\" is not a valid board size, try again:\n", buffer);
            continue;
        }
        return size;
    }
}

char **allocateBoard(int size){
    int i;
    char **board = NULL;
    board = malloc(sizeof(char*)*size);
    if(board == NULL){
        fprintf(stderr, "Could not allocate %ld bytes:", sizeof(char*)*size);
        perror("");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < size; i++){
        *(board+i) = malloc(sizeof(char));
        if(*(board+i) == NULL){
            fprintf(stderr, "Could not allocate %ld bytes:", sizeof(char)*size);
            perror("");
            exit(EXIT_FAILURE);
        }
    }
    return board;
}

int **allocateStateArray(int size) {
    int i = 0;
    int **state = (int**)malloc(size * sizeof(int*));
    for(i = 0; i < size; i++) {
        state[i] = (int*)malloc(size * sizeof(int));
    }
    return state;
}

void freeBoard(char **board, int size){
    int i;
    for(i = 0; i < size; i++)
        free(*(board+i));
    free(board);
}

// Clear the game board.
void clearBoard(char **board, int size) {
    int i = 0;
    int j = 0;
    
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            board[i][j] = 'B';
}

// Clear the state array.
void clearStateArray(int **array, int size) {
    int i = 0;
    int j = 0;
    
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            array[i][j] = 0;
}

// Function prints the game board.
void printBoard(char **board, int size) {
    int i, j;
    int digits = 0;
    int spaces = 1;
    int n;
    
    n = size;
    while(n != 0){
        n/=10;
        spaces++;
    }
    //Print first line
    printf("%*s", spaces, " ");
    for(i = 0; i < size; i++)
        printf("%c ", 'A'+i);
    printf("\n");
    //Print rows
    for(i = size-1; i >= 0; i--){
        n = i;
        digits = 0;
        if(n == 0)
            digits = 1;
        else
            while(n != 0){
                n/=10;
                digits++;
            }
        printf("%d%*s", i, spaces-digits, " ");
        for(j = 0; j < size; j++){
            printf("%c ", board[j][i]);
        }
        printf("\n");
    }
}
