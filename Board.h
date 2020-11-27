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

  private: //private variables, etc.
    //int example_var
  
  public: //function prototypes, etc.

    void DrawFullBoard(); 
    /*Draw the entire game board, square by square
      Ideally, only use to initally draw board
      Clears screen before drawing board
    */
  
};
