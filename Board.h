#pragma once //don't include multiple copies in final compilation
/** @file Board.h
 *  @brief Contains the class definition and prototypes for the Board class
 * */
#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "config.h"
#include "Game.h"

#define _USE_MATH_DEFINES
#include <cmath>


/**
 * @brief Stores and dislays game state. 
 * Responsible for keeping track of, and updating, where chips are located.
 * */
class Board {

  private:

    /** Local master array storing the game as a grid of integers representing chips and spaces.
     * */
    int board_state[BOARD_ROWS][BOARD_COLUMNS];

    /** Column that the board is currently manipulating
     * */
    int current_column;

    /** Current row a falling chip is in
     * */
    int current_row;

    /** Pixel coords of a falling chip
     * */
    int chip_x, chip_y;

  public:

    /** @brief Constructs an object of the Board class, setting local and global arrays.
     *  @details Initializes all elements of the board_state array to 0. Then pushes the contents of board_state to game_state.
     *  @param game_state Array to push contents board_state into
     *  @author Adam Exley
     * */
    Board(int game_state[BOARD_ROWS][BOARD_COLUMNS]);

    /** @brief Resets all variables.
     *  @details Same as constructor.
     *  @author Adam Exley
     * */
    void Reset(int game_state[BOARD_ROWS][BOARD_COLUMNS]);



    /** @brief Draws entire game board with chips.
     *  @details Calls DrawChips() to draw game chips
     *  @author Adam Exley
     * */
    void DrawBoard(); 
  
    /** @brief Draws only the chips of the game. Skips redrawing board.
     *  @author Adam Exley
     * */
    void DrawChips();

    /** @brief Draws the options menu to the left of the gameboard
     *  @author Lauren Pokonosky
     * */
    void DrawBoardMenu();



    /** @brief Checks if making a move in current_column is valid by seeing
     *  if the top row of current_column is occupied.
     *  @returns True/false of if said move can be performed
     *  @author Pietro Lavezzo
     * */
    bool isValidMove();

    /** @brief Waits for a touch and returns the value of the column that was touched.
     *  Also stores this value in the current_column variable.
     *  @returns A column value, or MAIN_MENU_CALL_VALUE or EXIT_CALL_VALUE 
     *  @author Lauren Pokonosky
     * */
    int getCurrentColumn();

    /** @brief Changes current_column. For use with AI.
     *  @param column Value to set current_column (and thus the move)
     *  @author Pietro Lavezzo
     * */
    void getAIMove(int column);



    /** @brief Animates chip dropping
     *  @param current_player The current player ID, used to set chip color
     *  @author Pietro Lavezzo
     * */
    void dropChip(int current_player);

  private:

    /** @brief Obscures chip "behind" game board while falling
     *  @details Only called by dropChip(), private function.
     *  @author Adam Exley
     * */
    void occludeChip();

  public:
    
    /** @brief Updates the game_state array to contain a new chip
     *  in a certain column. Uses the player paramater as the value in 
     *  the array 
     *  @param player Integer value (1 or 2) to set the array cell as
     *  @param game_state Array to update
     *  @author Adam Exley
     * */
    void updateGameState(int player, int game_state[BOARD_ROWS][BOARD_COLUMNS]);

  private:

    /** @brief Pushes contents of board_state into game_state
     *  @details Called as a part of other functions, namely Board() and updateGameState() in order to
     *  sync game_state with board_state when needed. Private for data integrity
     *  @param game_state Array to push contents board_state into
     *  @author Adam Exley
     * */
    void pushGameState(int game_state[BOARD_ROWS][BOARD_COLUMNS]);



  public:

    /** @brief Determines if a player has won.
     *  Tests all possible orientations and positions of getting 4 in a row.
     *  @returns The ID of the winning player (1 or 2), 3 for a tie, otherwise returns 0.
     *  @author Adam Exley
     * */
    int checkWin();
};
