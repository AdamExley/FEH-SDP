#pragma once

/** @file AI.h
 *  @brief Contains declarations of AI class functions.
 * */

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"
#include "config.h"
#include <climits>
#include <cmath>

//These websites were used in creating this code
//https://connect4.gamesolver.org
//https://www.wikihow.com/Win-at-Connect-4


/** @brief Computer controlled AI that has easy and hard difficulties. Makes decisions to output a desired move.
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
    int test_game_state_1[BOARD_ROWS][BOARD_COLUMNS];

    /** Internal copy of master game state array that is changed and tested
     *  Second level
     * */
    int test_game_state_2[BOARD_ROWS][BOARD_COLUMNS];

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
  
  public: 

    /** @author Adam Exley
     *  @brief Constructs AI object, setting difficulty to easy,
     *  ai_id to 2, and player_id to 1
     * */
    AI();

    /** @author Adam Exley
     *  @brief Sets difficulty variable of AI object
     *  @param diff AI difficulty (0 = Easy, 1 = Hard)
     * */
    void setDifficulty(bool diff);

    /** @author Adam Exley
     *  @brief Picks a move given the current game state
     *  @details Looks at possible moves and moves that could be played on those moves,
     *  and gives each move a score based on that. Picks the highest scoring move.
     *  @returns The column to make a move in
     * */
    int pickMove(const int game_state_array[BOARD_ROWS][BOARD_COLUMNS]);

  private:

    /** @author Lauren Pokonosky
     *  @brief Easy difficulty AI move generator.
     *  @details A random number generator. Called by pickMove() if on easy difficulty.
     *  @returns A column (0-6) of a move.
     * */
    int easyMove();

    /** @author Pietro Lavezzo
     *  @brief Checks if a move in is possible in a column
     *  @details Modified from Board::isValidMove(). Called by pickMove()
     *  @param column Column to see if move is valid in
     *  @param array Which array to test validity on.
     *  @returns True/false as to if move is valid in given array
     * */
    bool isValidMove(int column, const int array[BOARD_ROWS][BOARD_COLUMNS]);

    /** @author Adam Exley
     *  @brief Determines how many X-in-a-row combinations exist for a player.
     *  @details Will count multiple smaller structures inside a larger structure.
     *  For example, one 4-in-a-row is also 2 instances of 3-in-a-row and 3 instances of 2-in-a-row.
     *  Factors in whether or not a combination can be played on.
     *  Called by pickMove().
     *  @param x The number of chips in a row to detect.
     *  @param player The integer to analyze in the array.
     *  @param array Array to analyze. game_state or test_game_state_1
     *  @returns Combonations of x-in-a-row chips found that can be played on to get 4 in a row.
     * */
    int inARow(const int x, const int player, const int array[BOARD_ROWS][BOARD_COLUMNS]);

    /** @author Adam Exley
     *  @brief Measures how close a player's chips are towards the center.
     *  @details Called by pickMove().
     *  @param player The player ID to analyze
     *  @param array The array to analyze
     *  @returns The average distance from the center column
     * */
    double fromCenter(int player, const int array[BOARD_ROWS][BOARD_COLUMNS]);

    
};



