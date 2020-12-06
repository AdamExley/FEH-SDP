/** @file Board.cpp
 * This contains all the definitions for the Board class.
 * Declarations are in Board.h
 * */

#include "Board.h"

Board::Board(int game_state[BOARD_ROWS][BOARD_COLUMNS]){
	//Adam Exley

	//Sets board_state to all 0's
	for(int r = 0; r < BOARD_ROWS; r++){
		for (int c = 0; c < BOARD_COLUMNS; c++){
			board_state[r][c] = 0;
		}
	}

	//sends board_state to specified array
	pushGameState(game_state);

}


void Board::Reset(int game_state[BOARD_ROWS][BOARD_COLUMNS]){
	//Adam Exley

	//Sets board_state to all 0's
	for(int r = 0; r < BOARD_ROWS; r++){
		for (int c = 0; c < BOARD_COLUMNS; c++){
			board_state[r][c] = 0;
		}
	}
	
	//sends board_state to specified array
	pushGameState(game_state);

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


bool Board::isValidMove(){
	//Pietro Lavezzo

	//Checks to see if a move in the current_column is valid

	if  (board_state[0][current_column] != 0) {      //Checking if the top row of the pressed column is full 
		return 0;                                  //If so, return 0
	}
	else if (board_state[0][current_column] == 0) {   //Checking if the top row of the pressed column is empty
		return 1;                                   //If so, return 1
	}

	return 0; //Shouldn't reach here
}



int Board::getCurrentColumn() {
	//Lauren Pokonosky
	int x, y;

	waitForInput(x, y); //Waits for user to click a location on the board
	
	if (0<=x && x<=40) {
		current_column = 0;
			if (5<=x && x<=35 && 10<=y && y<=70) { //if statement for Home Button
				return MAIN_MENU_CALL_VALUE; //return the call value for main menu
			}
			else if (5<=x && x<=35 && 150<=y && y<=223) { //else if for Quit Button
				return EXIT_CALL_VALUE; //return exit call value
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


void Board::getAIMove(int column){
	//Pietro Lavezzo
	current_column = column;
}



void Board::dropChip(int current_player) {
	//Pietro Lavezzo
    float time = 1.0, x_position;
    int current_height, time_delay = 5, target_y;
    
    //Pass the current_player variable in the Chip function
    
	//Set the lowest y position of the chip as the target
	//taken from updateGameState
    for(target_y = BOARD_ROWS - 1; board_state[target_y][current_column] != 0; target_y--){

	}
	target_y = (target_y + 1) * 40 + 20;

    //Set the x position of the chip based on the column that was deicded by user/AI
    x_position = (current_column*40) + 60;

    //Understand which pixel the top of the chip is
    chip_y = (BOARD_ROWS) * 40;

    //This will redraw the circle at a faster rate as it goes down the screen
    for (current_height = 0; current_height <= target_y; current_height = (G * pow(time,2) + current_height) )
    {
        //If structure to decide which color to draw the chip  
        if (current_player == 1)
        {
           LCD.SetDrawColor(PLAYER_1_COLOR);
        }  //player 1 IF
        if (current_player == 2)
        {
            LCD.SetDrawColor(PLAYER_2_COLOR);
        } //player 2 IF
      
        LCD.FillCircle(x_position, current_height, 15);           //Draw the chip in a spceicif (x,y) coordinate
		current_row = (current_height - 20) / SQUARE_SIDE;		  //Update current row

		occludeChip();											  //Draw over the chip

        Sleep(time_delay);                                        //Keep the chip in that location for 0.1 seconds
        LCD.SetDrawColor(BLACK);                                  //Redraw a black chip over it, "earasing" the earlier chip.
        LCD.FillCircle(x_position, current_height, 15);
        time = time + 0.01;                                        //Change the time in the current_height function to better simulate gravity

    }
}


void Board::occludeChip(){
	//Adam Exley

	int x;
	int z;
	LCD.SetDrawColor(BOARD_COLOR);

	//Proteus doesnt like drawing at -y values, do special case if in top row
	if(current_row == 0){

		//Bottom block
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 5, (current_row + 1) * SQUARE_SIDE - 5, 30, 10);
		//Top blocks
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 5 , 0, 30,  5);
		//Special middle ones
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 5 , 0,  3, 16);
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 8 , 0,  3, 12);
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 11, 0,  3,  9);
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 2) - 7 , 0,  3, 16);
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 2) - 10, 0,  3, 12);
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 2) - 13, 0,  3,  9);

		x = 1; //skip doing top section of left/right rectangles below
		z = 2;
	}else if (current_row >= BOARD_ROWS - 1){
		//Proteus doesnt like drawing below the screen. Again, do special case.
		current_row = BOARD_ROWS - 1;

		//Bottom block
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 5, (current_row + 1) * SQUARE_SIDE - 5, 30, 5);
		//Top block
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 5 , 234, 30,  4);
		//Middle blocks
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 5 , 223,  3, 15);
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 8 , 227,  3, 11);
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 11, 230,  3,  8);
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 2) - 7 , 223,  3, 15);
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 2) - 10, 227,  3, 11);
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 2) - 13, 230,  3,  8);

		x = 0; //skip part of middle blocks below
		z = 1;
	}
	else{
		//Top block
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 5, current_row * SQUARE_SIDE - 5, 30, 10);

		x = 0; //do top and bottom sections below
		z = 2;
	}
	

	for(; x < z; x++){
		//Approximate circular hole with 6 rectangles

		//Left 1
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 5, (current_row + x) * SQUARE_SIDE - 16, 3, 32);
		//Left 2
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 8, (current_row + x) * SQUARE_SIDE - 12, 3, 24);
		//Left 3
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 1) + 11, (current_row + x) * SQUARE_SIDE - 9, 3, 18);

		//Right 1
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 2) - 7, (current_row + x) * SQUARE_SIDE - 16, 3, 32);
		//Right 2
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 2) - 10, (current_row + x) * SQUARE_SIDE - 12, 3, 24);
		//Right 3
		LCD.FillRectangle(SQUARE_SIDE*(current_column + 2) - 13, (current_row + x) * SQUARE_SIDE - 9, 3, 18);
	}


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



void Board::pushGameState(int game_state[BOARD_ROWS][BOARD_COLUMNS]){
	//Adam Exley

	//Copy board_state to specified array
	for(int r = 0; r < BOARD_ROWS; r++){
		for(int c = 0; c < BOARD_COLUMNS; c++){
			game_state[r][c] = board_state[r][c];
		}
	}
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

	//No win found, but check for full board (tie)
	bool tie = true; //assume board is full

	//cycle through entire board
	for(int r = 0; r < BOARD_ROWS; r++){
		for(int c = 0; c < BOARD_COLUMNS; c++){

			//if any spot is empty, there is no tie
			if(board_state[r][c] == 0){
				tie = false;
			}
		}
	}
	
	//return 3 for a tie
	if(tie){
		return 3;
	}




	//no win found 
	return 0;
}