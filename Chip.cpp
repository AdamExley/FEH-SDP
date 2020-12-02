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

void Chip::Drop() {
    int current_row;
    float chip_velocity, conversion_constant, time, x_position;
    int height_change, current_height;
    
    x_position = (current_column*40) + 60;
    conversion_constant = 20;
    int time_delay = 100;

    time = time_delay/1000;
    //Understand which pixel the top of the chip is
    chip_y = (current_row) * 40;

    //Set the height to a reasonable height for a Connect Four Board so the chips being dropped to the bottom don't go too fast
    //height_change = chip_y / conversion_constant;

    //This will redraw the circle at a faster rate as it goes down the screen
    for (current_height = 0; current_height <= chip_y; current_height = (G * pow(time,2) + current_height) )
    {
        LCD.DrawCircle(x_position, current_height, 15);
        Sleep(time_delay);  
    }
}

// void Chip::example_function(){   }
