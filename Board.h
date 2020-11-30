#pragma once //don't include multiple copies in final compilation
/*
Board header file
Contains the class definition and prototypes for the Board class
*/

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"


#define SQUARE_SIDE 40 //side length of each board tile
#define HOLE_RADIUS 15 //radius of the hole of each tile
#define BOARD_ROWS 6
#define BOARD_COLUMNS 7

class Board {

  private:

    int game_state[BOARD_ROWS][BOARD_COLUMNS];
    /*Array representing the current game state
      Uses different integers to correspond to different player's chips
    */
  
  public:

    Board();
    /*Constructor
      Initializes game_state array to all 0's
    */

    void DrawBoard(); 
    /*Draw the entire game board, square by square
    */

   void DrawChips();
   /*Draw only the chips on the board.
    Skips redrawing the board itself.
    */

   int checkWin();
   /*Takes the array representing the state of the game
     Checks for 4 of any integer in a row
     If found, returns said integer, otherwise returns 0
   */
  
};
