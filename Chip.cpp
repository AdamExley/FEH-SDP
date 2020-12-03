/*
Chip.cpp
This contains all the definitions for the Chip class.
Declarations are in Chip.h
*/
#include "FEHLCD.h"
#include "AI.h"
#include "Chip.h"
#include "Board.h"
#include "Chip.h"
#include "math.h"

#define G 9.81

void Chip::Drop(int current_player) {
    float chip_velocity, conversion_constant, time, x_position;
    int current_height, time_delay = 10;
    
    //Pass the current_player variable in the Chip function
    
    
    //Set the x position of the chip based on the column that was deicded by user/AI
    x_position = (current_column*40) + 60;

    //Set a variable for time used in the current_height equation
    time = time_delay/time_delay;
   
    //Understand which pixel the top of the chip is
    chip_y = (BOARD_ROWS) * 40;

    //This will redraw the circle at a faster rate as it goes down the screen
    for (current_height = 0; current_height <= chip_y; current_height = (G * pow(time,2) + current_height) )
    {
        //If structure to decide which color to draw the chip  
        if (current_player == 1)
        {
           LCD.SetDrawColor(PLAYER_1_COLOR);
        }  //player 1 IF
        if (current_player == 2)
        {
            LCD.SetDrawColor(PLAYER_2_COLOR);
        } //player 2 IF
      
        LCD.FillCircle(x_position, current_height, 15);           //Draw the chip in a spceicif (x,y) coordinate
        Sleep(time_delay);                                        //Keep the chip in that location for 0.1 seconds
        LCD.SetDrawColor(BLACK);                                  //Redraw a black chip over it, "earasing" the earlier chip.
        LCD.FillCircle(x_position, current_height, 15);
        time = time + 0.1;                                        //Change the time in the current_height function to better simulate gravity

    }
}

Chip::Chip()
:current_column(0)
{}
