#pragma once

/** @file Menu.h
 *  @brief Contains the class definition and prototypes for the Menu class
 * */

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"
#include "config.h"

/** @brief Displays all menus for game and stores current menu state.
 * */
class Menu{
    private:
      /** Stores current menu state
       *  
       *  0 - Main
       *  1 - Play
       *  2 - Stats
       *  3 - Instructions
       *  4 - Credits
       *  5 - Exit
       * */
      int menu_state;

      /** @author Lauren Pokonosky
       *  @brief Draws return and exit buttons
       * */
      void drawReturnExit();

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
       *  @brief Displays an exit screen thanking the user for playing
       * */
      void showExit();

      /** @author Adam Exley
       *  @brief Executes the function associated with a certain touch location
       *  @param x X-location of touch
       *  @param y Y-location of touch
       *  @returns True/false corresponding as to if the menu selection should continue looping
       * */
      bool checkTouchLocation(int x, int y);

};