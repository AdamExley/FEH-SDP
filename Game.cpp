/** @file Game.cpp
 *  @brief Contains definitions of functions in use throughout the entire game and the game class
 * 
 * */
#include "Game.h"


Game::Game()
//Adam Exley
//Construct, setting current player to 1
:current_player(1)
{}


void Game::Reset(){
    //Pietro Lavezzo
    current_player = 1;     //Sets current player back to 1
}


void Game::setSingleplayer(bool single){
    //Pietro Lavezzo

    singleplayer = single;      //Sets singleplayer variable
}


int Game::getCurrentPlayer(){
    //Pietro Lavezzo

    return current_player;      //Outputs current player variable
}

bool Game::isPlayerTurn(){
    //Pietro Lavezzo 

    if(singleplayer == false){
        return true;        //In multiplayer it's always a player's turn
    }
    else
    {
        if(current_player == 1)
        {
            return true;    //If singleplayer, player is 1
        }
        else
        {
            return false;   //If singleplayer, AI is player 2, return false
        }
    }
}

void Game::switchPlayer(){
    // Adam Exley

    //Switch player value from 1/2
    if(current_player == 1){
        current_player = 2;
    }
    else{
        current_player = 1;
    }
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
