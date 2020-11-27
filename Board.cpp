/*
Chip.cpp
This contains all the definitions for the Chip class.
Declarations are in Chip.h
*/

#include "Board.h"


// void Board::example_function(){   }

void Board::DrawFullBoard(){

    // draw the game board
    // start at bottom of , centering it.

    for(int r = 0, y = 239 - SQUARE_SIDE; r < BOARD_ROWS; r++, y = y - SQUARE_SIDE){
        //draw BOARD_ROWS rows starting from bottom

        for(int c = 0, x = ((320 - BOARD_COLUMNS*SQUARE_SIDE) / 2) - 1; c < BOARD_COLUMNS; c++, x = x + SQUARE_SIDE){
            // draw BOARD_COLUMNS columns starting from left
            
            //Game tiles
            LCD.SetDrawColor(LCD.Blue); //set game board color to be blue
            LCD.FillRectangle(x, y, SQUARE_SIDE, SQUARE_SIDE);
            //Tile Holes
            LCD.SetDrawColor(LCD.Black); //set tile holes to be black
            LCD.FillCircle(x + SQUARE_SIDE/2, y + SQUARE_SIDE/2, HOLE_RADIUS);
        }

    }


}