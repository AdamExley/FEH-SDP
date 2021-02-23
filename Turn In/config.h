#pragma once
/** @file config.h
 *  @brief Contains global constants that can be modified to change program behavior.
 * */

//Menu Options
#define BUTTON_COLOR SCARLET    //Background color for all menu buttons
#define TEXT_COLOR WHITE        //Text color for all menu buttons

//Board and Chip Colors
#define BOARD_COLOR BLUE                //Color of game board
#define BOARD_BACKGROUND_COLOR BLACK    //Color behind game board. Same as board hole color.
#define PLAYER_1_COLOR RED              //Color of player 1's chips
#define PLAYER_2_COLOR YELLOW           //Color of player 2's chips


//Board Options
#define SQUARE_SIDE 40  //Side length of each board tile
#define HOLE_RADIUS 15  //Radius of the hole of each tile
#define BOARD_ROWS 6    //Rows of the game board
#define BOARD_COLUMNS 7 //Columns in the game board
#define G 9.8           //Gravity multiplier


//Menu Options
#define MAIN_MENU_CALL_VALUE 10 //Value other class' touch functions can return to go to main menu
#define EXIT_CALL_VALUE 11      //Value other class' touch functions can return to exit game

//AI Scoring Options
#define CENTER_WEIGHT 10        //Value to weight moves towards center of board
#define ONE_PLAYABLE 10         //Value to give a single chip that can be played to 4
#define TWO_IN_A_ROW 30         //Value to give combos of 2 in a row that can be played to 4
#define THREE_IN_A_ROW 85       //Value to give combos of 3 in a row that can be played to 4
#define FOUR_IN_A_ROW 100000    //Value to give combos of 4 in a row 


//Image Options
#define DISABLE_VALUE 4000 //Arbitrary value to set a color's RGB values to when disabled.

/** @brief Optimization Constant.
 *  @details The number of pixels required padding a region of pixels in order to
 *  replace the region with the surrounding color. 
 * */
#define PER_SIDE 6

/** @brief Optimization Constant.
 *  @details The number of pixels in a row to attempt to change to another color if
 *  appropriately surounded by other pixels of consatnt color.
 * */
#define OPTIMIZE_WIDTH 3