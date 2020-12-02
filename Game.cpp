/** @file Game.cpp
 *  @brief Contains definitions of functions in use throughout the entire game
 * 
 * */
#include "Game.h"

Game::SinglePlayer(){//AI will be used 
    return true;
}
Game::MultiPlayer(){//AI is not necessary
    return false;
}

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
