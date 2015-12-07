/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * 
 */

#include <stdio.h>
#define pmBUFFER 4 /*for playerMove buffer*/

#ifndef FREEDOMMOVES_H
    #define FREEDOMMOVES_H
    // Function declarations go here.
	void getPlayerMove(char playerMove[]);
	void convertPlayerMove(char playerMove[], int size, int *rowCoordinate, int *columnCoordinate);
	int isValid(int turn, char **board, int freedom, int size, int previousRowCoordinate, int previousColumnCoordinate, int rowCoordinate, int columnCoordinate);
	int adjacentTiles(int previousRowCoordinate, int previousColumnCoordinate, int rowCoordinate, int columnCoordinate);
	void implementPlayerMove(int player, int coordinates[], char **board);
    
#endif
