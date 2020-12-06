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

        /** @author Adam Exley
         *  @brief Constructs, sets current player to 1
         * */
        Game();

        /** @author Pietro Lavezzo
         *  @brief Resets current player to 1
         * */
        void Reset();

        /** @author Pietro Lavezzo
         *  @brief Sets singleplayer status
         * */
        void setSingleplayer(bool single);

        /** @author Pietro Lavezzo
         *  @brief Gets current player
         *  @returns Current player ID
         * */
        int getCurrentPlayer();

        /** @author Pietro Lavezzo
         *  @brief Returns if it is currently a huamn player's turn
         *  @returns True/False as to if it is a human's turn
         * */
        bool isPlayerTurn();

        /** @author Adam Exley
         *  @brief switches the current player
         * */
        void switchPlayer();
};


//Non-class functions included to be used throughout program.

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
