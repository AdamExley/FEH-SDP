#pragma once
/** @file Menu.h
 *  @brief Contains the class definition and prototypes for the Menu class.
 * */

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "config.h"
#include "Game.h"
#include "image.h"

//Include data for TA/Instructor images.
#include "bridgette.c"
#include "bailey.c"
#include "alex.c"
#include "jamie.c"
#include "jane.c"
#include "paul.c"

/** @brief Displays all menus for game and stores current menu state.
 *  @details Also displays win/loss screens and statistics.
 * */
class Menu{
  private:
    /** Stores current menu state:
     *  0 - Main
     *  1 - Player Selection
     *  2 - Stats
     *  3 - Instructions
     *  4 - Credits
     *  5 - Exit
     *  6 - Difficulty Selection
     *  7 - Win/Loss Screen
     * */
    int menu_state;
    
    /** Stores if player selects a singleplayer game
     * */
    bool singleplayer;

    /** Stores difficulty selected by player in a singleplayer game
     * */
    bool difficulty;

    /** @brief Statistic
     *  @details The number of single player wins
     * */
    int single_player_wins;

    /** @brief Statistic
     *  @details The number of single player losses
     * */
    int AI_wins;

    /** @brief Statistic
     *  @details The least number of moves taken to beat an AI
     * */
    int fastest_win;

    /** @brief Statistic
     *  @details The number of multi player player 1 wins
     * */
    int multi_player_1_wins;

    /** @brief Statistic
     *  @details The number of multi player player 2 wins
     * */
    int multi_player_2_wins;

  public:

    /** @brief Constructs a Menu object. Sets initial values for stats/states 
     *  @author Adam Exley
     * */
    Menu();


    /** @brief Executes the menu function associated with a certain touch location
     *  @param x X-location of touch
     *  @param y Y-location of touch
     *  @returns True/false corresponding as to if the menu selection should continue looping
     *  @authors Adam Exley, Lauren Pokonosky
     * */
    bool checkTouchLocation(int x, int y);


    /** @brief Displays main menu
     *  @author Lauren Pokonosky
     * */
    void showMain();

  private:
    /** @brief Displays game selection menu. Allows seldction of Single/Multiplayer
     *  @author Lauren Pokonosky
     * */
    void showPlay();

    /** @brief Displays the option of choosing Easy or Hard gameplay in single player mode
     *  @author Lauren Pokonosky
     * */
    void showDifficulty();

    /** @brief Displays statistics on screen
     *  @author Lauren Pokonosky
     * */
    void showStats();

    /** @brief Displays game instructions
     *  @author Lauren Pokonosky
     * */
    void showInstructions();

    /** @brief Displays the credits for the game
     *  @author Lauren Pokonosky
     * */
    void showCredits();

    /** @brief Draws return and exit buttons
     *  @details Called by various menu display functions
     *  @author Lauren Pokonosky
     * */
    void drawReturnExit();

  public:

    /** @returns Value of difficulty variable
     *  @author Adam Exley
     * */
    bool getDifficulty();

    /** @returns Value of singleplayer variable
     *  @author Adam Exley
     * */
    bool getSingleplayer();
    
    /** @brief Updates the stats stored in the menu object
     *  @param winner Integer correspondng to winning player (1 or 2)
     *  @author Lauren Pokonosky
     * */
    void updateStats(int winner, int turns);

    /** @brief Shows win or loss screens with messages and a random TA.
     *  @details 
     *  @param winner Integer correspondng to winning player (1 or 2)
     *  @author Lauren Pokonosky
     * */
    void showWinLoss(int winner);

  private:

    /** @brief Displays a random TA image.
     *  @details Picks a random integer and then uses Img class to display a TA image.
     *  Called by showWinLoss().
     *  @author Lauren Pokonosky
     * */
    void displayTA();

  public:

    /** @brief Displays an exit screen thanking the user for playing. Runs forever
     *  @author Lauren Pokonosky
     * */
    void showExit();

};
