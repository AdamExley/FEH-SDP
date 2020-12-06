#pragma once
/** @file Game.h
 *  @brief Contains declarations of functions in use throughout the entire game and the game class
 * */
#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"
#include "config.h"

/** @brief Controls flow of the game once in play.
 *  @details Keeps track of AI/Player turns.
 * */
class Game{

    private:
        /** Stores the player the game is currently on
         * */
        int current_player;

        /** Stores if the game is single or multiplayer
         *  True = singleplayer, False = Multiplayer
         * */
        bool singleplayer;


    public:

        /** @brief Constructs, sets current player to 1
         *  @author Adam Exley
         * */
        Game();

        /** @brief Resets current player to 1
         *  @author Pietro Lavezzo
         * */
        void Reset();

        /** @brief Sets singleplayer status
         *  @author Pietro Lavezzo
         * */
        void setSingleplayer(bool single);

        /** @brief Gets current player
         *  @returns Current player ID
         *  @author Pietro Lavezzo
         * */
        int getCurrentPlayer();

        /** @brief Returns if it is currently a huamn player's turn
         *  @returns True/False as to if it is a human's turn
         *  @author Pietro Lavezzo
         * */
        bool isPlayerTurn();

        /** @brief switches the current player
         *  @author Adam Exley
         * */
        void switchPlayer();
};


//Non-class functions included to be used throughout program.

/** @brief Makes program idle until a touch is detected
 *  @param x address to store x coord of touch
 *  @param y address to store y coord of touch
 *  @author Adam Exley
 * */
void waitForInput(int *x, int *y);

/** @brief Makes program idle until a touch is detected
 *  @param x variable to store x coord of touch
 *  @param y variable to store y coord of touch
 *  @author Adam Exley
 * */
void waitForInput(int &x, int &y);
