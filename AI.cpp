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
    double temp = TimeNow();


    //Hard Difficulty from here on

    /** Strategies:
     *  - Prefer the center of the board
     *  - Try to get 4 in a row
     *  - Try to get 3 in a row
     *  - Try to get 2 in a row
     * 
     *  - Don't let the opponent do any of the above
     * */


    //Array to store "scores" for each possible move
    int move_score[BOARD_COLUMNS] = {0};
    int row; //used for dropping chips into valid spots

    //Copy game state to local variables for easier analysis
    for(int r = 0; r < BOARD_ROWS; r++){
        for(int c = 0; c < BOARD_COLUMNS; c++){
            test_game_state_1[r][c] = game_state_array[r][c];
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

        //reset test_game_state_1 to current state of board
        for(int r = 0; r < BOARD_ROWS; r++){
            for(int c = 0; c < BOARD_COLUMNS; c++){
                test_game_state_1[r][c] = game_state[r][c];
            }
        }

        //Drop chip into test_game_state_1 at the move being analyzed
        //Taken from Board::updateGameState()
            //decrement r until the row r is empty
            //In the lowest empty row, place the chip with value of ai_id
        for(row = BOARD_ROWS - 1; test_game_state_1[row][move] != 0; row--);
        test_game_state_1[row][move] = ai_id;

        //Test to see if this move results in a win. If it does, return it as the move to use.
        if(inARow(4, ai_id, test_game_state_1) > 0){
            return move;
        }

        //Second-level move check. Move_2 is the move that the opponent can make after move "move" is made
        //Allows to test for if making move "move" allows the opponent to easily win
        //Very similar to structure leading up to this
        for(int move_2 = 0; move_2 < BOARD_COLUMNS; move_2++){

            //Test move_2 validity
            if(!isValidMove(move_2, test_game_state_1)){
                //If invalid, skip to next analysis
                continue;
            }

            //reset test_game_state_2 to test_game_state_1
            for(int r = 0; r < BOARD_ROWS; r++){
                for(int c = 0; c < BOARD_COLUMNS; c++){
                    test_game_state_2[r][c] = test_game_state_1[r][c];
                }
            }

            //make move_2 in test_game_state_2
            for(row = BOARD_ROWS - 1; test_game_state_2[row][move_2] != 0; row--);
            test_game_state_2[row][move_2] = player_id;

            //change the move score based on analysis

            //Benefits to AI
            move_score[move] += ONE_PLAYABLE * inARow(1, ai_id, test_game_state_2);
            move_score[move] += TWO_IN_A_ROW * inARow(2, ai_id, test_game_state_2);
            move_score[move] += THREE_IN_A_ROW * inARow(3, ai_id, test_game_state_2);
                //Theoretically this should never occur, but covering bases
            move_score[move] += FOUR_IN_A_ROW * inARow(4, ai_id, test_game_state_2);
                //Other player deviating from center is a pro
            move_score[move] += CENTER_WEIGHT * fromCenter(player_id, test_game_state_2);

            //Benefits to player
            move_score[move] -= ONE_PLAYABLE * inARow(1, player_id, test_game_state_2);
            move_score[move] -= TWO_IN_A_ROW * inARow(2, player_id, test_game_state_2);
            move_score[move] -= THREE_IN_A_ROW * inARow(3, player_id, test_game_state_2);
            move_score[move] -= FOUR_IN_A_ROW * inARow(4, player_id, test_game_state_2);
            move_score[move] -= CENTER_WEIGHT * fromCenter(ai_id, test_game_state_2);

        }


    }

    //Set best move to be first move initally 
    int max_score = move_score[0];
    int best_move = 0;

    //Determine which move has max move score
    for(int i = 0; i < BOARD_COLUMNS; i++){

        if(move_score[i] > max_score){
            max_score = move_score[i];
            best_move = i;
        }
    }


//************************************************ DELETE
    LCD.WriteAt(TimeNow()-temp, 50, 225);

    Sleep(2.0);
//*************************************************


    return best_move;

}


int AI::easyMove(){
    int rand = RandInt();
    int easy_move = rand % 7;
    return easy_move;
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

    return false; //Shouldn't reach here

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
    bool playable;

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

            //If all values were equal to player, check if playable
            if (equal){

                //w is starting offset of a 4-chip row
                for(int w = x - 4; w < 1; w++){
                    //Make sure not out of bounds
                    if((r + w < 0) || (r - w >= BOARD_ROWS)){
                        continue;
                    }

                    playable = true; //assume it's playable

                    //Check that a 4-chip sequence starting at the w offset can be made
                    for(int z = 0; (z < 4) && equal; z++){
                        
                        //If not playable, change variable
                        if(!(array[r + w + z][c] == 0 || array[r + w + z][c] == player)){
                            playable = false;
                        }

                    }

                    //if a 4-chip combo can be made off this piece location and size, increase count
                    if(playable){
                        count++;
                    }

                }

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

                //w is starting offset of a 4-chip combo
                for(int w = x - 4; w < 1; w++){
                    
                    //Make sure not out of bounds
                    if((c + w < 0) || (c - w >= BOARD_COLUMNS)){
                        continue;
                    }

                    playable = true; //assume it's playable

                    //Check that a 4-chip sequence starting at the w offset can be made
                    for(int z = 0; (z < 4) && equal; z++){
                        
                        //If not playable, change variable
                        if(!(array[r][c + w + z] == 0 || array[r][c + w + z] == player)){
                            playable = false;
                        }

                    }

                    //if a 4-chip combo can be made off this piece location and size, increase count
                    if(playable){
                        count++;
                    }

                }
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

                //w is starting offset of a 4-chip combo
                for(int w = x - 4; w < 1; w++){

                    //Make sure not out of bounds
                    if(((c + w < 0) || (c - w >= BOARD_COLUMNS)) || ((r + w < 0) || (r - w >= BOARD_ROWS))){
                        continue;
                    }

                    playable = true; //assume it's playable

                    //Check that a 4-chip sequence starting at the w offset can be made
                    for(int z = 0; (z < 4) && equal; z++){
                        
                        //If not playable, change variable
                        if(!(array[r + w + z][c + w + z] == 0 || array[r + w + z][c + w + z] == player)){
                            playable = false;
                        }

                    }

                    //if a 4-chip combo can be made off this piece location and size, increase count
                    if(playable){
                        count++;
                    }

                }
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

                //w is starting offset of a 4-chip combo
                for(int w = x - 4; w < 1; w++){

                    //Make sure not out of bounds
                    if(((c + w < 0) || (c - w >= BOARD_COLUMNS)) || ((r + w < 0) || (r - w >= BOARD_ROWS))){
                        continue;
                    }

                    playable = true; //assume it's playable

                    //Check that a 4-chip sequence starting at the w offset can be made
                    for(int z = 0; (z < 4) && equal; z++){
                        
                        //If not playable, change variable
                        if(!(array[r - (w + z)][c + w + z] == 0 || array[r - (w + z)][c + w + z] == player)){
                            playable = false;
                        }

                    }

                    //if a 4-chip combo can be made off this piece location and size, increase count
                    if(playable){
                        count++;
                    }

                }
            }
		}
	}

	//return number of matches found 
	return count;
}



double AI::fromCenter(int player, const int array[BOARD_ROWS][BOARD_COLUMNS]){
    //Adam Exley

    double cumlative_dist = 0;
    int count = 0;

    for(int c = 0; c < BOARD_COLUMNS; c++){
        for(int r = 0; r < BOARD_ROWS; r++){
            if(array[r][c] == player){
                count++;
                cumlative_dist += fabs(c - ((BOARD_COLUMNS - 1) / 2));
            }
        }
    }

    return (cumlative_dist / count);

}

