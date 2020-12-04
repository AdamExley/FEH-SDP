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

    /** Internal copy of master game state array
     * */
    int game_state[BOARD_ROWS][BOARD_COLUMNS];

    /** @author Lauren Pokonosky
     *  @brief Easy difficulty AI move generator.
     *  @details A random number generator.
     * */
    int easyMove();
  
  public: 

    /** @brief Sets difficulty variable of AI object
     * */
    void setDifficulty(bool diff);

    int pickMove(const int game_state_array[BOARD_ROWS][BOARD_COLUMNS]);

    int inARow(const int x, const int player);

    
};


/** Strategies:
 *  - Prefer the center of the board
 *  - Try to get 4 in a row
 *  - Try to get 3 in a row
 *  - Try to get 2 in a row
 * 
 *  - Don't let the opponent do any of the above
 * */

