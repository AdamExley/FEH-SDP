/*
AI.cpp
Contains all code for the AI class.
Declarations are in AI.h
*/

#include "FEHRandom.h"
#include "AI.h"

void AI::setDifficulty(bool diff){
    difficulty = diff;
}

int AI::pickMove(const int game_state_array[BOARD_ROWS][BOARD_COLUMNS]){

    //If set to easy, return an easy move
    if(!difficulty){
        return easyMove();
    }

    //Hard Difficulty
    //Copy game state to local variable for easier analysis

    for(int r = 0; r < BOARD_ROWS; r++){
        for(int c = 0; c < BOARD_COLUMNS; c++){
            game_state[r][c] = game_state_array[r][c];
        }
    }



}


int AI::easyMove(){
    int rand = RandInt();
    int easy_move = rand % 7;
    return easy_move;
}


int AI::inARow(const int x, const int player) {
	//Written by Adam Exley

	//Check for X chips in a row in any orientation
    //Paramaterized version of Board::checkWin() that returns a count

    int count = 0;

	/*************** Vertical ********************/

	//Use starting points in upper half of board
	//Go to last row that has X-1 rows below it
	for (int r = 0; r < BOARD_ROWS - x + 1; r++){

		//Starting points in all columns
		for (int c = 0; c < BOARD_COLUMNS; c++){

			//Check if the starting point is equal to desired player
			if (game_state[r][c] == player) {

				//Check if top 2 values are equal
				if (game_state[r][c] == game_state[r + 1][c]) {

					//Check if bottom 2 values are equal
					if (game_state[r+2][c] == game_state[r+3][c]){

						//Check that both top and bottom sets are equal
						if (game_state[r][c] == game_state[r+2][c]){

							//There is a win
							//Return the value that won
							return game_state[r][c];
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
			if (game_state[r][c]) {

				//Check if left 2 values are equal
				if (game_state[r][c] == game_state[r][c + 1]) {

					//Check if right 2 values are equal
					if (game_state[r][c + 2] == game_state[r][c + 3]) {

						//Check that both left and right sets are equal
						if (game_state[r][c] == game_state[r][c + 2]) {

							//There is a win
							//Return the value that won
							return game_state[r][c];
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
			if (game_state[r][c]) {

				//Check that top left 2 values are equal
				if (game_state[r][c] == game_state[r + 1][c + 1]) {

					//Check that bottom right 2 values are equal
					if (game_state[r + 2][c + 2] == game_state[r + 3][c + 3]) {

						//Check that top left and bottom right segs are equal
						if (game_state[r][c] == game_state[r + 2][c + 2]) {

							//There is a win
							//Return the value that won
							return game_state[r][c];
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
			if (game_state[r][c]) {

				//Check that bottom left 2 values are equal
				if (game_state[r][c] == game_state[r - 1][c + 1]) {

					//Check that top right 2 values are equal
					if (game_state[r - 2][c + 2] == game_state[r - 3][c + 3]) {

						//Check that top right and bottom left segs are equal
						if (game_state[r][c] == game_state[r - 2][c + 2]) {

							//There is a win
							//Return the value that won
							return game_state[r][c];
						}
					}
				}
			}
		}
	}


	//no win found 
	return 0;
}
