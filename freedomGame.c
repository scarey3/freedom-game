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

void clearBoard(char **board, int size);
void printBoard(char **board, int size);
char** allocateBoard(int size);
void freeBoard(char **board, int size);
int getSize();

int main(void) {
    char **board;
    int size = getSize();
    
    board = allocateBoard(size);
    clearBoard(board, size);
    printBoard(board, size);
    
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
        if(size < MIN_SIZE){
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
        fprintf(stderr, "Could not allocate %d bytes:", sizeof(char*)*size);
        perror("");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < size; i++){
        *(board+i) = malloc(sizeof(char));
        if(*(board+i) == NULL){
            fprintf(stderr, "Could not allocate %d bytes:", sizeof(char)*size);
            perror("");
            exit(EXIT_FAILURE);
        }
        **(board+i) = ' ';
    }
    return board;
}

void freeBoard(char **board, int size){
    int i;
    for(i = 0; i < size; i++)
        free(*(board+i));
    free(board);
}

void clearBoard(char **board, int size) {
    int i = 0;
    int j = 0;
    
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            board[i][j] = ' ';
}

// Function prints the board.
void printBoard(char **board, int size) {
    int i = 0;
    int j = 0;
    
    printf("  ");
    for(i = 0; i < size; i++){
        printf(" [%c]", i + 65);
    }
    
    for(i = 0; i < size; i++) {
        printf("\n[%d] ", i);
        for(j = 0; j < size; j++)
            printf("%c   ", board[i][j]);
        printf("\n");
    }
}
