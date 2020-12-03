/**************************************************/
/* FEH SDP                                        */
/* Adam Exley, Lauren Pokonosky, Pietro Lavezzo   */
/* Connect 4                                      */
/* Clingan 8:00     10/30/20                      */
/* Ver 0.2                                        */
/**************************************************/

//General headers
#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"

//Include class headers
#include "AI.h"
#include "Chip.h"
#include "Board.h"
#include "Menu.h"
#include "Game.h"
#include "image.h"

#include "bridgette.c"
#include "bailey.c"
#include "alex.c"
#include "jamie.c"
#include "jane.c"
#include "paul.c"

#include "logo_b.c"




/*************************************************** Main *****************/

/**
 * Entry point to the application.
 * 
 * @returns status code of program exit
 */

int main() {

    int game_state[BOARD_ROWS][BOARD_COLUMNS];

    AI ai;
    Chip chip;
    Board board(game_state);
    Menu menu;


    // int bailey_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN};
    // Img bailey(bailey_enable, 5);
    // bailey.Draw(bailey_data, BAILEY_FRAME_WIDTH, BAILEY_FRAME_HEIGHT, 1, BLACK);
    // Sleep(5.0);
    // LCD.Clear();

    // int bridgette_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN};
    // Img bridgette(bridgette_enable, 5);
    // bridgette.Draw(bridgette_data, BRIDGETTE_FRAME_WIDTH, BRIDGETTE_FRAME_HEIGHT, 1, BLACK);
    // Sleep(5.0);
    // LCD.Clear();

    // int alex_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN, BLUE};
    // Img alex(alex_enable, 6);
    // alex.Draw(alex_data, ALEX_FRAME_WIDTH, ALEX_FRAME_HEIGHT, 1, BLACK);
    // Sleep(5.0);
    // LCD.Clear();

    int paul_enable[] = {BLACK, WHITE, GRAY, OLIVE, MAROON, CYAN};
    Img paul(paul_enable, 6);
    paul.Draw(paul_data, PAUL_FRAME_WIDTH, PAUL_FRAME_HEIGHT, 1, BLACK, 0);
    Sleep(5.0);
    LCD.Clear();

    int jamie_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN, MAROON};
    Img jamie(jamie_enable, 6);
    jamie.Draw(jamie_data, JAMIE_FRAME_WIDTH, JAMIE_FRAME_HEIGHT, 1, BLACK);
    Sleep(5.0);
    LCD.Clear();

    int jane_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN, MAROON};
    Img jane(jane_enable, 6);
    jane.Draw(jane_data, JANE_FRAME_WIDTH, JANE_FRAME_HEIGHT, 1, BLACK);
    Sleep(5.0);
    LCD.Clear();

    // LCD.Clear(WHITE);

    // int enabled[] = {WHITE, RED, BLACK, YELLOW, GRAY};
    // Img connect4logo(enabled, 5);
    // connect4logo.Draw(logo_2b, 160, 51, 2, WHITE, false);

    // Sleep(5.0);

    int x, y;

    //show main menu at beginning of game
    menu.showMain();


    while(true){

    do{
        //get touch location
        waitForInput(x, y); 

        //execute command associated with location based on menu state
        //loop until a selection is chosen that requires a menu to not be displayed
    }while(menu.checkTouchLocation(x, y));

    //after menu is done executing, begin playing game

    //create game, setting it to if the user selected single or multiplayer
    Game game(menu.getSingleplayer());

    //if in a singleplayer game, set the AI difficulty
    if(menu.getSingleplayer()){
        ai.setDifficulty(menu.getDifficulty());
    }

    //Do inital draw of board and board menu
    board.DrawBoard();
    board.DrawBoardMenu();

    //initialize a temporary variable
    int temp;

    do{
        if(game.isPlayerTurn()){

            do{
                temp = board.getCurrentColumn();

                if(temp == MAIN_MENU_CALL_VALUE || temp == EXIT_CALL_VALUE){
                    break;
                }

            }while(!board.isValidMove());

            if(temp == MAIN_MENU_CALL_VALUE || temp == EXIT_CALL_VALUE){
                break;
            }
            
            board.updateGameState(game.getCurrentPlayer(), game_state);
            

        }
        else{
            // ai.PickMove(game_state);

            // board.updateGameState(2);

        }
        board.DrawChips();
        game.switchPlayer();
    }while(!board.checkWin());
    //Show win/loss screen
    delete (&game); //destruct game instance

    if(temp == MAIN_MENU_CALL_VALUE){
        menu.showMain();
    }else if(temp == EXIT_CALL_VALUE){
        menu.showExit();
    }

    }
    return 0;
}
