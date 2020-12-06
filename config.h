/** @file config.h
 *  @brief Contains global constants that can be modified to change program behavior.
 * */

//Menu Options
#define BUTTON_COLOR LCD.Scarlet    //Background color for all menu buttons
#define TEXT_COLOR LCD.White        //Text color for all menu buttons

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

#define G 9.8


//Menu Options
#define MAIN_MENU_CALL_VALUE 10 //Value other class' touch functions can return to go to main menu
#define EXIT_CALL_VALUE 11      //Value other class' touch functions can return to exit game

//AI Scoring Options
#define CENTER_WEIGHT 2 //Value to weight moves towards center of board
#define ONE_PLAYABLE 5  //Value to give a single chip that can be played to 4
#define TWO_IN_A_ROW 15 //Value to give combonations of 2 in a row
    //Value to give combonations of 3 in a row above base. Base value will be 2 * TWO_IN_A_ROW
#define THREE_IN_A_ROW 45 
    //Value to give combonations of 4 in a row above base. Base value will be 2 * THREE_IN_A_ROW + 3 * TWO_IN_A_ROW
#define FOUR_IN_A_ROW 100000 


//Image Options

/** Arbitrary value to set a color's RGB values to when disabled.
 * */
#define DISABLE_VALUE 4000

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