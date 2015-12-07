/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * Freedom Game. An "n-in-a-row" board game.
 */

#include <stdio.h>
#include "freedomMoves.h"
#include "freedomScoring.h"

/*prototype declarations*/


/*****************Main***************/
int main() {
    char **board; /*board*/
    char playerMove[pmBUFFER]; /*holds player coordinates*/
	int size = 10;
	//int coordinates[cBUFFER]; /*holds converted coordinates (row, column) of playerMove*/
	int previousRowCoordinate, previousColumnCoordinate; /*previous row, column coordinates*/
	int rowCoordinate, columnCoordinate; /*holds converted coordinates (row, column) of playerMove*/
	int freedom = 0;
	int turn = 0;
	int valid = 0;
	int player = 1;
	
	/*clear playerMove*/
    memset(playerMove, '\0', pmBUFFER);
	
	/*welcome message. Get user input*/
	printf("Welcome to Freedom! White goes first! Please choose a space.\n");
	getPlayerMove(playerMove);
	
	/*convert user input*/
	convertPlayerMove(playerMove, size, &rowCoordinate, &columnCoordinate);
	printf("Row is: %d\nColumn is: %d\n", rowCoordinate, columnCoordinate);
	
	/*validate user input*/
	if(isValid(turn, board, freedom, size, previousRowCoordinate, previousColumnCoordinate, rowCoordinate, columnCoordinate) == 1){
		printf("The move is valid!");
	}
	else{
		printf("The move is not valid");
	}
	/*place piece on board*/
	
	/*change player turn*/
		
	
  	return 0;
}
/*******************Functions********************/


	
	

