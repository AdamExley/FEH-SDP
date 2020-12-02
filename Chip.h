#pragma once

/** @file Chip.h
 *  @brief Contains the class definition and prototypes for the Chip class
 * */

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"
#include "config.h"

class Chip {
  private: //private variables, etc.
    int chip_x;
    int chip_y;
    int current_column;
  
  public: //function prototypes, etc.
    void Drop();
  
};



