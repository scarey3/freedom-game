/* Violet Pfeiffer, Adam Capar, Samuel Carey
 * Project 3
 * 25 November 2015
 * 
 */
#include "freedomMoves.h"
#include <ctype.h>
#include <string.h>

/*******************Functions********************/
/*Retrieves and returns the player's input*/
void getPlayerMove(char playerMove[]){
	/*Clear buffer. Get user input*/
	fflush(stdin);
	fgets(playerMove, pmBUFFER, stdin);
	//printf("%c %c %c %c\n", playerMove[0], playerMove[1], playerMove[2],playerMove[3]);
	
	/*if column is not lowercase OR uppercase char*/
	/*if(!((playerMove[0] >= 'a' && playerMove[0] <= 'z') || (playerMove[0] >= 'A' && playerMove[0] <= 'Z'))){
		printf("Sorry, the column you entered was incorrect. Please enter coordinates again.\n");
		getPlayerMove(playerMove);
	}
	
	/*row is not a single digit*/
	if(!(playerMove[1] >= '1' && playerMove[1] <= '9')){
		printf("Sorry, the row you enterred was incorrect. Please enter coordinates again.\n");
		getPlayerMove(playerMove);
	}
	
	/*row is not a double digit*/
	/*if((!(playerMove[2] == '\0')) || (!(playerMove[2] >= '0' && playerMove[2] <= '9'))){
		printf("Sorry, the row you enterred was incorrect. Please enter coordinates again.\n");
		getPlayerMove(playerMove);
	}*/
	return;
}

/*convert user input to tile position*/
void convertPlayerMove(char playerMove[], int size, int *rowCoordinate, int *columnCoordinate){
	/*TODO: move valid characters checking to getPlayerMove function*/
	long row; /*holds row converted to long*/
	char *ptr; /*useless null pointer. (for strtol())*/
	char str1[3]; /*for strtol()*/
	char str2[2]; /*for strtol()*/
	
	/*clear str1, str2*/
	memset(str1, '\0', 3);
	memset(str2, '\0', 2);
	
	/*column*/
	/*check if column is lowercase*/
	if(playerMove[0] >= 'a' && playerMove[0] <= 'z'){
		/*convert column to upper case*/
		playerMove[0] = toupper(playerMove[0]);
	}
	/*convert column from capital char to int*/
	if(playerMove[0] >= 'A' && playerMove[0] <= 'Z'){
		//printf("converting char to column...\n");
		*columnCoordinate = playerMove[0] - 'A'; //<--offset necesary to convert to ints
	}
	/*user input for column is not an alphabetical char*/
	/*else{
		printf("Sorry, the column you entered was incorrect. Please enter coordinates again.\n");
		getPlayerMove(playerMove);
	}*/
	
	/*row*/
	/*if row coordinate lower than 10*/
	if(playerMove[1] >= '1' && playerMove[1] <= '9'){
		//printf("converting row...\n");
		
		/*checks if second coordinate is 10 or greater*/
		if(playerMove[2] >= '0' && playerMove[2] <= '9'){
			
			/*convert to long*/
			str1[0] = playerMove[1];
			str1[1] = playerMove[2];

			row = strtol(str1, &ptr, 10);
			/*store to coordinate variable*/
			*rowCoordinate = (int)row-1;
			
		}
		/*if row is single digit*/
		else if(!(playerMove[2] >= '0' && playerMove[2] <= '9')){
		
			/*convert to long*/
			str2[0] = playerMove[1];
			row = strtol(str2, &ptr, 10);
			
			/*if row > 0, subtract 1*/
			*rowCoordinate = (int)row-1;
		}
		//printf("long row is %l\n", row);
		/*store to coordinate variable*/
		//*rowCoordinate = (int)row-1;
	}
	/*user input for row is not a numerical char*/
	/*else{
		printf("Sorry, the column you enterred was incorrect. Please enter coordinates again.\n");
		getPlayerMove(playerMove);
	}*/

	return;
}

/*check if tile position is valid. Return 1 if true, 0 if false*/
int isValid(int turn, char **board, int freedom, int size, int previousRowCoordinate, int previousColumnCoordinate, int rowCoordinate, int columnCoordinate){ //FIX ME: make more general
	//printf("Made it in to isValid. Checking if within bounds of board...\n");
	/*if playerMove is within bounds of board*/
	if(rowCoordinate >= 0 && rowCoordinate <= size){
		if(columnCoordinate >= 0 && columnCoordinate <= size){
			/*if its turn 0*/
			if(turn == 0){
				return 1;
			}
			/*if tile is empty*/
			if(board[rowCoordinate][columnCoordinate] == ' '){
				/*if freedom mechanic is true. (all adjacent tiles are filled)*/
				if(freedom == 1){ //FIX ME: may have to check this my self
					return 1;
				} 
				/*if the position is adjacent to last move*/
				/*call to adjacentTiles()*/
				if(adjacentTiles(previousRowCoordinate, previousColumnCoordinate, rowCoordinate, columnCoordinate) == 1){
					return 1;
				}
			}
			
		}
	}
	
	/*if both elements of playerMove are NOT valid return 0*/
	return 0;
}
/*check adjacent tiles of previous move. Return 1 if true, 0 if false*/
int adjacentTiles(int previousRowCoordinate, int previousColumnCoordinate, int rowCoordinate, int columnCoordinate){
	/*column -1*/
	if(previousColumnCoordinate - 1 == columnCoordinate){
		/*row == row*/
		if(previousRowCoordinate == rowCoordinate){
			return 1;
		}
		/*row + 1*/
		if(previousRowCoordinate + 1 == rowCoordinate){
			return 1;
		}
		/*row - 1*/
		if(previousRowCoordinate - 1 == rowCoordinate){
			return 1;
		}
		return 0;
	}
	
	/*row -1*/
	if(previousRowCoordinate - 1 == rowCoordinate){
		/*column == column*/ 
		if(previousColumnCoordinate == columnCoordinate){
			return 1;
		}
		/*column + 1*/
		if(previousColumnCoordinate + 1 == columnCoordinate){
			return 1;
		}
		return 0;
	}
	
	/*column + 1*/
	if(previousColumnCoordinate + 1 == columnCoordinate){
		/*row == row*/
		if(previousRowCoordinate == rowCoordinate){
			return 1;
		}
		
		/*row + 1*/
		if(previousRowCoordinate + 1 == rowCoordinate){
			return 1;
		}
		return 0;
	}
	
	/*row + 1*/
	if(previousRowCoordinate + 1 == rowCoordinate){
		
		/*column == column*/
		if(previousColumnCoordinate == columnCoordinate){
			return 1;
		}
		return 0;
	}

}
/*place piece on tile position*/
void implementPlayerMove(int player, int coordinates[], char **board){
	
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