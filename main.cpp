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

#include "connect_4_logo.c"
#include "logo_a.c"
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
    
    //int enabled[] = {WHITE, RED, MAROON, BLACK, YELLOW};
    //Img connect4logo(enabled, 5);
    //connect4logo.Draw(connect_4_logo, 320, 106);
    //Sleep(5.0);

    LCD.Clear(WHITE);

    int enabled[] = {WHITE, RED, BLACK, YELLOW};
    Img connect4logo(enabled, 4);
    //connect4logo.Draw(logo_2, 320, 101);
    connect4logo.Draw(logo_2b, 160, 51, 2, WHITE);
    Sleep(5.0);

    int x, y;

    //show main menu at beginning of game
    menu.showMain();

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

    //Do inital draw of board
    board.DrawBoard();

    // do{
    //     if(game.isPlayerTurn()){

    //         do{
    //             board.getCurrentColumn();
    //         }while(!board.isValidMove());
            
    //         board.updateGameState(game.getCurrentPlayer());

    //     }
    //     else{
    //         ai.PickMove(game_state);

    //         board.updateGameState(2);

    //     }

    // }while(!board.checkWin());
    // Show win/loss screen
    // delete game; //destruct game instance



    return 0;
}
