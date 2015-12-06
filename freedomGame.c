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
	//int coordinates[cBUFFER]; /*holds converted coordinates (row, column) of playerMove*/
	int previousRowCoordinate, previousColumnCoordinate; /*previous row, column coordinates*/
	int rowCoordinate, columnCoordinate; /*holds converted coordinates (row, column) of playerMove*/
	int turn = 0;
	int valid = 0;
	int player = 1;
	
	/*clear playerMove*/
    memset(playerMove, '\0', pmBUFFER);
	
  	return 0;
}
/*******************Functions********************/
/*game logic*/
void playGame(void){
	char newGame = 'Y'; /*if player wants to play new game*/
	char playerMove[pmBUFFER]; /*holds player move*/
	int coordinates[cBUFFER]; /*holds converted coordinates (row, column) of playerMove*/
	
	
	/*while(newGame == 'Y'|| newGame =='y'){
		/*print board*/
		//printBoard(board[][COLUMNS]);
		
		/*welcome message. Get user input*/
		/*printf("Welcome to Freedom! White goes first! Please choose a space.\n");
		getPlayerMove(playerMove);*/
		
		/*convert user input*/
		
		/*validate user input*/
		
		/*place piece on board*/
		
		/*change player turn*/
		
	/*}*/	
	
}

