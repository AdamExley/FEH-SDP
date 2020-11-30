#include "FEHLCD.h"
#include "AI.h"
#include "Chip.h"
#include "Board.h"

/*
screen is 320 by 240
*/


void waitForInput(int *x, int *y);
void waitForInput(int &x, int &y);
/*Makes program idle until a touch is detected.
  Returns x and y coords of a touch.
  Overloaded to accept variables or addresses of variables
*/



/**
 * Entry point to the application.
 * 
 * @returns status code of program exit
 */

int main() {
    AI ai;
    Chip chip;
    Board board;

    board.DrawNewBoard();


    while (1) {
        // Run forever
    }
    return 0;
    
}




void waitForInput(int &x, int &y){
    //Written by Adam Exley
    //Version for variable input
    //Do nothing until touch is registered
    while(!LCD.Touch(&x, &y)); 
}

void waitForInput(int *x, int *y){
    //Written by Adam Exley
    //Version for address input
    //Do nothing until touch is registered
    while(!LCD.Touch(x, y)); 
}