/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * 
 */

#include <stdio.h>

#ifndef FREEDOMSCORING_H
    #define FREEDOMSCORING_H
    
    #define ROWS 10
    #define COLUMNS 10
    
    void checkVertical(char **board, int **live, int size);
    void checkHorizontal(char **board, int **live, int size);
    void checkDiagonal(char **board, int **live, int size);
    
#endif
