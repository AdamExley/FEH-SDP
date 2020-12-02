#pragma once

/** @file AI.h
 *  @brief Contains declarations of AI class functions
 * */

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"

class AI {
  private: 
    /** Correpsonds to the selected difficulty of AI.
     *  False is easy, true is hard.
     * */
    bool difficulty;
  
  public: 

    /** @brief Sets difficulty variable of AI object
     * */
    void setDifficulty(bool diff);

    int pickMove(const int game_state_array[]);
  
};




