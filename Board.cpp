/** @file Board.cpp
 * This contains all the definitions for the Board class.
 * Declarations are in Board.h
 * */

#include "Board.h"

Board::Board(int game_state[BOARD_ROWS][BOARD_COLUMNS]){


	for(int r = 0; r < BOARD_ROWS; r++){
		for (int c = 0; c < BOARD_COLUMNS; c++){
			board_state[r][c] = 0;
		}
	}

	pushGameState(game_state);

}

void Board::DrawBoardMenu(){ //Drawing the menu that will display on the left of the board
	//Lauren Pokonosky
	
  	LCD.SetDrawColor(BUTTON_COLOR);
	
	LCD.FillRectangle(5, 10, 30, 70);
	LCD.FillRectangle(5, 150, 30, 73);
	
	LCD.SetFontColor(TEXT_COLOR);
	
	LCD.WriteAt("H", 13, 12);
   	LCD.WriteAt("o", 13, 30);
   	LCD.WriteAt("m", 13, 48);
   	LCD.WriteAt("e", 13, 66);

  	LCD.WriteAt("Q", 13, 152);
    	LCD.WriteAt("u", 15, 170);
    	LCD.WriteAt("i", 17, 188);
    	LCD.WriteAt("t", 16, 206);	
}

void Board::DrawBoard(){
	//Adam Exley

    // Draw the full game board
    // start at bottom of the screen, justifying the board to the right

	//Set draw color to the specified board color
	LCD.SetDrawColor(BOARD_COLOR);

	//Draw large rectangle for game board
	//Determine size and location based on rows, columns, and size of the tiles
	LCD.FillRectangle((320 - BOARD_COLUMNS * SQUARE_SIDE), 0, SQUARE_SIDE * BOARD_COLUMNS, SQUARE_SIDE * BOARD_ROWS);

	//Draw the chips in the board
	DrawChips();

}


void Board::DrawChips(){
	//Adam Exley

	//Draw the chips of the board
	//Use constants in config.h to determine the color of holes

 for(int r = BOARD_ROWS - 1, y = 239 - SQUARE_SIDE; r >= 0; r--, y = y - SQUARE_SIDE){
        //draw BOARD_ROWS rows of chips starting from bottom

        for(int c = 0, x = (320 - BOARD_COLUMNS * SQUARE_SIDE); c < BOARD_COLUMNS; c++, x = x + SQUARE_SIDE){
            // draw BOARD_COLUMNS columns of chips starting from left

            //Chip Colors
			switch (board_state[r][c]){
				//Use int stored in game_state to determine if a chip is in place. 

            	case 0:
					//Set holes to be background color
			    	LCD.SetDrawColor(BOARD_BACKGROUND_COLOR);
					break;
								
		  		case 1:
					//Set holes to be player 1's color
					LCD.SetDrawColor(PLAYER_1_COLOR);
					break;
								
				case 2:
					//Set holes to be player 2's color
					LCD.SetDrawColor(PLAYER_2_COLOR);
			    	break;
			}
			//Draw circle in the middle of the rectangle with specified color.
            LCD.FillCircle(x + SQUARE_SIDE/2, y + SQUARE_SIDE/2, HOLE_RADIUS);
        }
    }
}


int Board::getCurrentColumn() {
	//Lauren Pokonosky
	int x, y;

	waitForInput(x, y); //Waits for user to click a location on the board
	
	if (0<=x && x<=40) {
		current_column = 0;
			if (5<=x && x<=35 && 10<=y && y<=70) { //if statement for Home Button
				menu.showMain();
			}
			else if (5<=x && x<=35 && 150<=y && y<=223) { //else if for Quit Button
				menu.showExit();
			}	
	}
	else if (40<x && x<=80) {
		current_column = 1;
	}
	else if (80<x && x<=120) {
		current_column = 2;
	}
	else if (120<x && x<=160) {
		current_column = 3;
	}
	else if (160<x && x<=200) {
		current_column = 4;
	}
	else if (200<x && x<=240) {
		current_column = 5;
	}
	else if (240<x && x<=280) {
		current_column = 6;
	}
	else if (280<x && x<=320) {
		current_column = 7;
	}

	current_column--;

	return current_column;
}


int Board::checkWin() {
	//Written by Adam Exley

	//Check for 4 chips in a row in any orientation

	/*************** Vertical ********************/

	//Use starting points in upper half of board
	//Go to last row that has 3 rows below it
	for (int r = 0; r < BOARD_ROWS - 3; r++){

		//Starting points in all columns
		for (int c = 0; c < BOARD_COLUMNS; c++){

			//Check if the starting point is nonzero
			if (board_state[r][c]) {

				//Check if top 2 values are equal
				if (board_state[r][c] == board_state[r + 1][c]) {

					//Check if bottom 2 values are equal
					if (board_state[r+2][c] == board_state[r+3][c]){

						//Check that both top and bottom sets are equal
						if (board_state[r][c] == board_state[r+2][c]){

							//There is a win
							//Return the value that won
							return board_state[r][c];
						}
					}
				}
			}
		}
	}


	/*************** Horizontal ********************/

	//Use starting points in left half of board
	//Go to last column with 3 columns to the right
	for (int c = 0; c < BOARD_COLUMNS - 3; c++) {

		//Starting points in all rows
		for (int r = 0; r < BOARD_ROWS; r++) {

			//Check if the starting point is nonzero
			if (board_state[r][c]) {

				//Check if left 2 values are equal
				if (board_state[r][c] == board_state[r][c + 1]) {

					//Check if right 2 values are equal
					if (board_state[r][c + 2] == board_state[r][c + 3]) {

						//Check that both left and right sets are equal
						if (board_state[r][c] == board_state[r][c + 2]) {

							//There is a win
							//Return the value that won
							return board_state[r][c];
						}
					}
				}
			}
		}
	}


	/************ Diagonal \ **********/

	//Start in upper left corner
	//Go to last row that has 3 rows below it
	for(int r = 0; r < BOARD_ROWS - 3; r++) {

		//Go to last column that has 3 columns to the right
		for (int c = 0; c < BOARD_COLUMNS - 3; c++) {

			//Check that top left value is nonzero
			if (board_state[r][c]) {

				//Check that top left 2 values are equal
				if (board_state[r][c] == board_state[r + 1][c + 1]) {

					//Check that bottom right 2 values are equal
					if (board_state[r + 2][c + 2] == board_state[r + 3][c + 3]) {

						//Check that top left and bottom right segs are equal
						if (board_state[r][c] == board_state[r + 2][c + 2]) {

							//There is a win
							//Return the value that won
							return board_state[r][c];
						}
					}
				}
			}
		}
	}

	/************ Diagonal / **********/

	//Start in bottom left corner
	//Go to last row that has 3 rows above it
	for (int r = BOARD_ROWS - 1; r > 2; r--) {

		//Go to last column that has 3 columns to the right
		for (int c = 0; c < BOARD_COLUMNS - 3; c++) {

			//Check that bottom left value is nonzero
			if (board_state[r][c]) {

				//Check that bottom left 2 values are equal
				if (board_state[r][c] == board_state[r - 1][c + 1]) {

					//Check that top right 2 values are equal
					if (board_state[r - 2][c + 2] == board_state[r - 3][c + 3]) {

						//Check that top right and bottom left segs are equal
						if (board_state[r][c] == board_state[r - 2][c + 2]) {

							//There is a win
							//Return the value that won
							return board_state[r][c];
						}
					}
				}
			}
		}
	}


	//no win found 
	return 0;
}



void Board::updateGameState(int player, int game_state[BOARD_ROWS][BOARD_COLUMNS]){
	//Adam Exley

	int r;
	//decrement r until the row r is empty
	for(r = BOARD_ROWS - 1; board_state[r][current_column] != 0; r--);
	
	//In the lowest empty row, place the chip with value "player"
	board_state[r][current_column] = player;

	pushGameState(game_state);
}




bool Board::isValidMove(){
	//Pietro Lavezzo

	//Checks to see if a move in the current_column is valid

	if  (board_state[0][current_column] != 0) {      //Checking if the top row of the pressed column is full 
		return 0;                                  //If so, return 0
	}
	else if (board_state[0][current_column] == 0) {   //Checking if the top row of the pressed column is empty
		return 1;                                   //If so, return 1
	}

}


void Board::pushGameState(int game_state[BOARD_ROWS][BOARD_COLUMNS]){

	for(int r = 0; r < BOARD_ROWS; r++){
		for(int c = 0; c < BOARD_COLUMNS; c++){
			game_state[r][c] = board_state[r][c];
		}

	}


}

