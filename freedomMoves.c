/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * 
 */
#include "freedomMoves.h"



/*******************Functions********************/
/*Retrieves and returns the player's input*/
void getPlayerMove(char playerMove[]){

	/*Get user input*/
	fgets(playerMove, pmBUFFER, stdin);
	//printf("%c %c %c %c\n", playerMove[0], playerMove[1], playerMove[2],playerMove[3]);
	
	return;
}

/*convert user input to tile position*/
void convertPlayerMove(char playerMove[], int coordinates[]){
	
	/*convert row from capital char to int*/
	coordinates[0] = playerMove[0] - 'A'; //<--offset necesary to convert to ints
	
	/*checks if second coordinate is 10*/
	if(playerMove[1] == '1' && playerMove[2]== '0'){
		//printf("converting 10 to 9\n");
		playerMove[1] = '9';
		coordinates[1] = playerMove[1] - '0'; //<-- offset adjusted for 10
	}
	else{
		/*convert column from numerical char to int*/
		coordinates[1] = playerMove[1] - '1'; //<-- offset isn't '0' because board numbers are offset by 1
	}
	
	return;
}

/*check if tile position is valid. Return 1 if true, 0 if false*/
int isValid(char playerMove[], int turn){//FIX ME: under construction

	/*if both elements of playerMove are valid return 1*/
	if(playerMove[0] >= 'A' &&  playerMove[0] <= 'J'){
		if(playerMove[1] >= '0' && playerMove[1] <= '9'){ //FIX ME: can't have multicharacter char
			if(turn == 0){
				return 1;
			}
			
		}
	}
	/*if both elements of playerMove are NOT valid return 0*/
	return 0;
}

/*place piece on tile position*/
void implementPlayerMove(int player, int coordinates[], char board[][COLUMNS]){
	
	/*check if player1 (white)*/
	if(player == 1){
		/*place white piece*/
		board[coordinates[0]][coordinates[1]] = 'W';
	}
	/*check if player2 (black)*/
	else if(player == 2){
		/*place black piece*/
		board[coordinates[0]][coordinates[1]] = 'B';
	}
	printf("%c\n", board[coordinates[0]][coordinates[1]]);
	return;
}