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

#include "scream.c"
#include "image.h"
#include "connect_4_logo.c"




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
    //Game game;

    int enabled[] = {WHITE, RED, MAROON, BLACK, YELLOW};
    Img connect4logo(enabled, 5);

    connect4logo.Draw(connect_4_logo, 320, 106);
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

    // if(game.isAIgame){
    //     ai.setDifficulty(game.getAIdifficulty());
    // }

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



    return 0;
}
