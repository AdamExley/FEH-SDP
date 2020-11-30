/**************************************************/
/* FEH SDP                                        */
/* Adam Exley, Lauren Pokonosky, Pietro Lavezzo   */
/* Connect 4                                      */
/* Clingan 8:00     10/30/20                      */
/* Ver 0.2                                        */
/**************************************************/

//General headers
#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"

//Include class headers
#include "AI.h"
#include "Chip.h"
#include "Board.h"
#include "Menu.h"


/**
 * @brief Makes program idle until a touch is detected
 * @param x address to store x coord of touch
 * @param y address to store y coord of touch
 * @returns Nothing
 * */
void waitForInput(int *x, int *y);
/** 
 * @brief Makes program idle until a touch is detected
 * @param x variable to store x coord of touch
 * @param y variable to store y coord of touch
 * @returns Nothing
 * */
void waitForInput(int &x, int &y);


/*************************************************** Main *****************/

/**
 * Entry point to the application.
 * 
 * @returns status code of program exit
 */

int main() {
    AI ai;
    Chip chip;
    Board board;
    Menu menu;

    int x, y;

    //show main menu at beginning of game
    menu.showMain();

    do{
        //get touch location
        waitForInput(x, y); 

        //execute command associated with location based on menu state
        //loop until a selection is chosen that requires a menu to not be displayed
    }while(menu.checkTouchLocation(x, y));

    return 0;
}

/*************************************************** Definitions *****************/


void waitForInput(int &x, int &y){
    //Written by Adam Exley
    //Version for variable input
    //Do nothing until touch is registered
    while(!LCD.Touch(&x, &y)); 
}

void waitForInput(int *x, int *y){
    //Adam Exley
    //Version for address input
    //Do nothing until touch is registered
    while(!LCD.Touch(x, y)); 
}

