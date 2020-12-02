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

#DEFINE G 9.81;

void Chip::Drop {
int current_row;
float chip_y, chip_velocity, conversion_constant, current_column, time;
int height_change, current_height;

conversion_constant = 20;
time_delay = 100;

time = time_delay/1000;
//Understand which pixel the top of the chip is
chip_y = (current_row) * 40;

//Set the height to a reasonable height for a Connect Four Board so the chips being dropped to the bottom don't go too fast
height_change = chip_y / conversion_constant;

//This will redraw the circle at a faster rate as it goes down the screen
for (current_height = 0; current_height <= height_change; current_height = (g*pow(time,2) + current_height) )
{
    LCD.DrawCircle(current_column, current_height, 15);
    Sleep(time_delay);  
}
}

// void Chip::example_function(){   }
