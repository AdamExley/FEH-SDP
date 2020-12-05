/** @file Game.cpp
 *  @brief Contains definitions of functions in use throughout the entire game and the game class
 * 
 * */
#include "Game.h"


Game::Game()
// Construct, setting current player to 1
:current_player(1)
{}

void Game::setSingleplayer(bool single){
    singleplayer = single;
}


int Game::getCurrentPlayer(){
    return current_player;
}

bool Game::isPlayerTurn(){
    if(!singleplayer){
        return true;
    }
    else
    {
        if(current_player == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Game::switchPlayer(){
    if(current_player == 1){
        current_player = 2;
    }
    else{
        current_player = 1;
    }
}


void Game::reset(){
    current_player = 1;
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
