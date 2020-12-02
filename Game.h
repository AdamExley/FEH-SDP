#pragma once

/** @file Game.h
 *  @brief Contains declarations of functions in use throughout the entire game
 * */

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"
#include "config.h"
#include "Menu.h"

class Game{

    private:
        bool Ai_game;
        int current_player;
        bool singleplayer;


        

    public:
        bool SinglePlayer();
        
        bool MultiPlayer();

        int getCurrentPlayer();

        bool isAIGame();

        bool isPlayerTurn();



};


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
