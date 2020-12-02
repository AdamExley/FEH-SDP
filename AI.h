#pragma once //don't include multiple copies in final compilation
/*
This is the AI Header File
It contains all class code and functions for the AI class
*/

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"

class AI {
  private: 

    int difficulty;
  
  public: 

    int pickMove(const int game_state_array[]);
  
};




