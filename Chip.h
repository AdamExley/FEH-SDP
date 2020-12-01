#pragma once //don't include multiple copies in final compilation
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
    int column;
  
  public: //function prototypes, etc.
    void Drop(int column);
  
};



