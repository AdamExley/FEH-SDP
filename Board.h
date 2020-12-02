#pragma once //don't include multiple copies in final compilation
/**
 * @file Board.h
 * @brief Contains the class definition and prototypes for the Board class
 * */

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"
#include "config.h"
#include "Game.h"




/**
 * @brief Stores and dislays game state 
 * */
class Board {

  private:

    /** Local master array storing the game as a grid of integers representing chips and spaces.
     * */
    int board_state[BOARD_ROWS][BOARD_COLUMNS];

    /** Column that the board is currently manipulating
     * */
    int current_column;

    /** @author Adam Exley
     *  @brief Pushes contents of board_state into game_state
     *  @details Called as a part of other functions, namely Board() and updateGameState() in order to
     *  sync game_state with board_state when needed.
     *  @param game_state Array to push contents board_state into
     * */
    void pushGameState(int game_state[BOARD_ROWS][BOARD_COLUMNS]);

  public:

    /** @author Adam Exley
     * @brief Constructs an object of the Board class, setting local and global arrays.
     * @details Initializes all elements of the board_state array to 0. Then pushes the contents of board_state to game_state.
     * @param game_state Array to push contents board_state into
     * */
    Board(int game_state[BOARD_ROWS][BOARD_COLUMNS]);

    /** @author Adam Exley
     *  @brief Draws entire game board with chips
     *  @public A
     *  @return Nothing
     * */
    void DrawBoard(); 

    /** @author Adam Exley
     *  @brief Draws only the chips of the game. Skips redrawing board.
     *  @return Nothing
     * */
    void DrawChips();


    /** @author Adam Exley
     *  @brief Determines if a player has won
     *  Tests all possible orientations and positions of getting 4 in a row.
     *  If a win is found: 
     *  @returns The ID of the winning player (1 or 2). Otherwise returns 0.
     * */
    int checkWin();

    /** @author Adam Exley
     *  @brief Updates the game_state array to contain a new chip
     *  in a certain column. Uses the player paramater as the value in 
     *  the array 
     *  @param player Integer value (1 or 2) to set the array cell as
     *  @param game_state Array to update
     * */
    void updateGameState(int player, int game_state[BOARD_ROWS][BOARD_COLUMNS]);

    /** @author Pietro Lavezzo
     *  @brief Checks if making a move in current_column is valid by seeing
     *  if the top row of current_column is occupied.
     *  @returns True/false of if said move can be performed
     * */
    bool isValidMove();

    /** @author Lauren Pokonosky
     *  @brief Waits for a touch and returns the value of the column that was touched.
     *  Also stores this value in the current_column variable.
     *  @returns A column value, -1 to 6, with -1 corresponding to the menu.
     * */
    int getCurrentColumn();


};
