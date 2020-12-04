#pragma once

/** @file AI.h
 *  @brief Contains declarations of AI class functions
 * */

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"
#include "config.h"
#include <climits>


//https://www.gamesver.com/10-helpful-tips-tricks-and-strategies-to-win-at-connect-4/
//https://en.wikipedia.org/wiki/Connect_Four#Mathematical_solution
//https://docs.microsoft.com/en-us/cpp/cpp/?view=msvc-160

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
    int ai_id;

    /** Player number of non-AI (default is 1).
     *  Mainly for testing by pitting AI's against each other.
     * */
    int player_id;

    /** @author Lauren Pokonosky
     *  @brief Easy difficulty AI move generator.
     *  @details A random number generator.
     *  @returns A column (0-6) of a move.
     * */
    int easyMove();

    /** @author Adam Exley
     *  @brief Determines how many X-in-a-row combinations exist for a player.
     *  @details Will count multiple smaller structures inside a larger structure.
     *  For example, one 4-in-a-row is also 2 instances of 3-in-a-row and 3 instances of 2-in-a-row.
     *  Does not factor in as to if the combos are able to be played on, as this should somewhat cancel out as
     *  the board states will be compared agaainst each other. May result in some inaccuracy.
     *  @param x The number of chips in a row to detect.
     *  @param player The integer to analyze in the array.
     *  @param array Array to analyze. game_state or test_game_state
     *  @returns Combonations of x-in-a-row chips found.
     * */
    int inARow(const int x, const int player, const int array[BOARD_ROWS][BOARD_COLUMNS]);
  
  public: 

    /** @brief Constructs AI object, setting difficulty to easy,
     *  ai_id to 2, and player_id to 1
     * */
    AI();

    /** @brief Sets difficulty variable of AI object
     * */
    void setDifficulty(bool diff);

    int pickMove(const int game_state_array[BOARD_ROWS][BOARD_COLUMNS]);

    /** @author Pietro Lavezzo
     *  @brief Checks if a move in is possible in a column
     *  @details Modified from Board::isValidMove()
     *  @param column Column to see if move is valid in
     *  @param array Which array to test validity on, test_game_state or game_state
     *  @returns True/false as to if move is valid in given array
     * */
    bool isValidMove(int column, const int array[BOARD_ROWS][BOARD_COLUMNS]);

    
};


/** Strategies:
 *  - Prefer the center of the board
 *  - Try to get 4 in a row
 *  - Try to get 3 in a row
 *  - Try to get 2 in a row
 * 
 *  - Don't let the opponent do any of the above
 * */

