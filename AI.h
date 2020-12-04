#pragma once

/** @file AI.h
 *  @brief Contains declarations of AI class functions
 * */

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"
#include "config.h"


//https://www.gamesver.com/10-helpful-tips-tricks-and-strategies-to-win-at-connect-4/
//https://en.wikipedia.org/wiki/Connect_Four#Mathematical_solution

/** @brief Computer controlled AI that has easy and hard difficulties.
 *  @details Easy difficulty is a mere random number generator.
 *  Hard difficulty does analysis on 1 future move using arbitrary scores for certain conditions.
 * */
class AI {
  private: 
    /** Correpsonds to the selected difficulty of AI.
     *  False is easy, true is hard.
     * */
    bool difficulty;

    /** Internal copy of master game state array that is changed and tested
     * */
    int test_game_state[BOARD_ROWS][BOARD_COLUMNS];

    /** Internal copy of master game state array that is constant
     * */
    int game_state[BOARD_ROWS][BOARD_COLUMNS];

    /** Player number of AI (default is 2).
     *  Mainly for testing by pitting AI's against each other.
     * */
    int player_number;

    /** @author Lauren Pokonosky
     *  @brief Easy difficulty AI move generator.
     *  @details A random number generator.
     *  @returns A column (0-6) of a move.
     * */
    int easyMove();

    /** @author Adam Exley
     *  @brief Determines how many X-in-a-row combonations exist for a player. Uses test_game_state array.
     *  @details Will count multiple smaller structures inside a larger structure.
     *  For example, one 4-in-a-row is also 2 instances of 3-in-a-row and 3 instances of 2-in-a-row.
     *  @param x The number of chips in a row to detect.
     *  @param player The integer to analyze in the array
     *  @returns Combonations of x-in-a-row chips found
     * */
    int inARow(const int x, const int player);
  
  public: 

    AI();

    /** @brief Sets difficulty variable of AI object
     * */
    void setDifficulty(bool diff);

    int pickMove(const int game_state_array[BOARD_ROWS][BOARD_COLUMNS]);

    /** @author Pietro Lavezzo
     *  @brief Checks if a move in test_game_state is possible in a column
     *  @details Modified from Board::isValidMove()
     *  @param column Column to see if move is valid in
     *  @returns True/false as to if move is valid in test_game_state
     * */
    bool isValidMove(int column);

  

    
};


/** Strategies:
 *  - Prefer the center of the board
 *  - Try to get 4 in a row
 *  - Try to get 3 in a row
 *  - Try to get 2 in a row
 * 
 *  - Don't let the opponent do any of the above
 * */

