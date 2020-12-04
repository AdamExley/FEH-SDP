/*
AI.cpp
Contains all code for the AI class.
Declarations are in AI.h
*/

#include "FEHRandom.h"
#include "AI.h"

AI::AI()
:difficulty(false), ai_id(2), player_id(1)
{}

void AI::setDifficulty(bool diff){
    difficulty = diff;
}

int AI::pickMove(const int game_state_array[BOARD_ROWS][BOARD_COLUMNS]){

    //If set to easy, return an easy move
    if(!difficulty){
        return easyMove();
    }

    //Hard Difficulty from here on

    //Array to store "scores" for each possible move
    int move_score[BOARD_COLUMNS] = {0};

    //Copy game state to local variables for easier analysis
    for(int r = 0; r < BOARD_ROWS; r++){
        for(int c = 0; c < BOARD_COLUMNS; c++){
            test_game_state[r][c] = game_state_array[r][c];
            game_state[r][c] = game_state_array[r][c];
        }
    }

    //Go through each column, and thus move possible in current state
    for(int move = 0; move < BOARD_COLUMNS; move++){

        //Check to see if move is valid in master game state
        if(!isValidMove(move, game_state)){
            //Move is invalid
            move_score[move] = INT_MIN; //Set to lowest possible integer value
            continue; //Skip further analysis
        }

        //reset test_game_state to current state
        for(int r = 0; r < BOARD_ROWS; r++){
            for(int c = 0; c < BOARD_COLUMNS; c++){
                test_game_state[r][c] = game_state[r][c];
            }
        }

        //Drop chip into test_game_state at the move being analyzed
        //Taken from Board::updateGameState()
            //decrement r until the row r is empty
            //In the lowest empty row, place the chip with value of ai_id
        int r;
        for(r = BOARD_ROWS - 1; test_game_state[r][move] != 0; r--);
        test_game_state[r][move] = ai_id;

        //Test to see if this move results in a win. If it does, return it as the move to use.
        if(inARow(4, ai_id, test_game_state) > 0){
            return move;
        }




    }



}


int AI::easyMove(){
    int rand = RandInt();
    int easy_move = rand % 7;
    return easy_move;
}


int AI::inARow(const int x, const int player, const int array[BOARD_ROWS][BOARD_COLUMNS]) {
	//Written by Adam Exley

	//Check for X chips in a row in any orientation
    //Paramaterized version of Board::checkWin() that returns a count

    /** Return count
     * */
    int count = 0;

    /** Logical value that stores if values are equal to desired player
     * */
    bool equal; 

	/*************** Vertical ********************/

	//Use starting points in upper half of board
	//Go to last row that has X-1 rows below it
	for (int r = 0; r < BOARD_ROWS - x + 1; r++){

		//Starting points in all columns
		for (int c = 0; c < BOARD_COLUMNS; c++){

            equal = true; //Assume match exists

            //Loop x times, finding if values are not equal to player
            //If not equal, break loop
            for (int z = 0; (z < x) && equal; z++){
                //Check values vertically
                if (array[r + z][c] != player){
                    equal = false;
                }
            }

            //If all values were equal to player, increase count
            if (equal){
                count++;
            }

		}
	}


	/*************** Horizontal ********************/

	//Use starting points in left half of board
	//Go to last column with X-1 columns to the right
	for (int c = 0; c < BOARD_COLUMNS - x + 1; c++) {

		//Starting points in all rows
		for (int r = 0; r < BOARD_ROWS; r++) {

            equal = true; //Assume match exists

            //Loop x times, finding if values are not equal to player
            //If not equal, break loop
            for (int z = 0; (z < x) && equal; z++){
                //Check values horizontally
                if (array[r][c + z] != player){
                    equal = false;
                }
            }

            //If all values were equal to player, increase count
            if (equal){
                count++;
            }
		}
	}


	/************ Diagonal \ **********/

	//Start in upper left corner
	//Go to last row that has x-1 rows below it
	for(int r = 0; r < BOARD_ROWS - x + 1; r++) {

		//Go to last column that has x-1 columns to the right
		for (int c = 0; c < BOARD_COLUMNS - x + 1; c++) {

            equal = true; //Assume match exists

            //Loop x times, finding if values are not equal to player
            //If not equal, break loop
            for (int z = 0; (z < x) && equal; z++){
                //Check values horizontally
                if (array[r + z][c + z] != player){
                    equal = false;
                }
            }

            //If all values were equal to player, increase count
            if (equal){
                count++;
            }
		}
	}

	/************ Diagonal / **********/

	//Start in bottom left corner
	//Go to last row that has x-1 rows above it
	for (int r = BOARD_ROWS - 1; r > (x - 2); r--) {

		//Go to last column that has x-1 columns to the right
		for (int c = 0; c < BOARD_COLUMNS - x + 1; c++) {

            equal = true; //Assume match exists

            //Loop x times, finding if values are not equal to player
            //If not equal, break loop
            for (int z = 0; (z < x) && equal; z++){
                //Check values horizontally
                if (array[r - z][c + z] != player){
                    equal = false;
                }
            }

            //If all values were equal to player, increase count
            if (equal){
                count++;
            }
		}
	}

	//return number of matches found 
	return count;
}


bool AI::isValidMove(int column, const int array[BOARD_ROWS][BOARD_COLUMNS]){
	//Pietro Lavezzo

	//Checks to see if a move in column is valid
	if  (array[0][column] != 0) {      //Checking if the top row of the column is full 
		return false;
	}
	else if (array[0][column] == 0) {   //Checking if the top row of the column is empty
		return true;
	}

}
