#pragma once

/** @file Game.h
 *  @brief Contains declarations of functions in use throughout the entire game
 * */

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"
#include "config.h"

/** @brief Controls flow of the game once in play.
 *  @details Keeps track of AI/Player turns, 
 * */
class Game{

    private:
        int current_player;
        bool singleplayer;


    public:

        Game();

        void setSingleplayer(bool single);

        int getCurrentPlayer();

        void switchPlayer();

        bool isPlayerTurn();

        void reset();
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
