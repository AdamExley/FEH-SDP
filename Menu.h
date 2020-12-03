#pragma once

/** @file Menu.h
 *  @brief Contains the class definition and prototypes for the Menu class
 * */

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"
#include "config.h"
#include "Game.h"
#include "image.h"


#include "bridgette.c"
#include "bailey.c"
#include "alex.c"
#include "jamie.c"
#include "jane.c"
#include "paul.c"

/** @brief Displays all menus for game and stores current menu state.
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
       * */
      int menu_state;
      
      /** Stores if player selects a singleplayer game
       * */
      bool singleplayer;

      /** Stores difficulty selected by player in a singleplayer game
       * */
      bool difficulty;


      int single_player_wins;
      int AI_wins;
      int multi_player_1_wins;
      int multi_player_2_wins;

      /** @author Lauren Pokonosky
       *  @brief Draws return and exit buttons
       * */
      void drawReturnExit();

      /** @author Lauren Pokonosky
       *  @brief Displays game selection menu
       * */
      void showPlay();

      /** @author Lauren Pokonosky
       *  @brief Displays statistics on screen
       * */
      void showStats();

      /** @author Lauren Pokonosky
       *  @brief Displays game instructions
       * */
      void showInstructions();

      /** @author Lauren Pokonosky
       *  @brief Displays the credits for the game
       * */
      void showCredits();

      /** @author Lauren Pokonosky
       *  @brief Displays the option of choosing Easy or Hard gameplay in single player mode
       * */
      void showDifficulty();


    public:

      /** @author Adam Exley
       *  @brief Constructs a Menu object. Sets menu_state to be 0.
       * */
      Menu();

      /** @author Lauren Pokonosky
       *  @brief Displays main menu
       * */
      void showMain();

      /** @author Lauren Pokonosky
       *  @brief Displays an exit screen thanking the user for playing
       * */
      void showExit();

      /** @returns Value of difficulty variable
       * */
      bool getDifficulty();

      /** @returns Value of singleplayer variable
       * */
      bool getSingleplayer();

      /** @authors Adam Exley, Lauren Pokonosky
       *  @brief Executes the menu function associated with a certain touch location
       *  @param x X-location of touch
       *  @param y Y-location of touch
       *  @returns True/false corresponding as to if the menu selection should continue looping
       * */
      bool checkTouchLocation(int x, int y);

      void showWinLoss(int winner);

      void displayTA();

      void updateStats(int winner);

};
