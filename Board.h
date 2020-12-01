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




/**
 * @brief Stores and dislays game state 
 * */
class Board {

  private:
    /**
     * Array representing the current game state
     * Uses different integers to correspond to different player's chips
     * */
    int game_state[BOARD_ROWS][BOARD_COLUMNS];

  public:

    /**
     * @brief Constructs an object of the Board class
     * Initializes all elements of the game_state array to 0.
     * */
    Board();

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


    void updateGameState(int column, int player);

  
};
