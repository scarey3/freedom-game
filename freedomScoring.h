/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef FREEDOMSCORING_H
    #define FREEDOMSCORING_H
    void score(char **board, int size);
    int** allocateStateArray(int size);
    void checkVertical(char **board, int **state, int size);
    void checkHorizontal(char **board, int **state, int size);
    void checkDiagonal(char **board, int **state, int size);
    
#endif
