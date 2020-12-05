/**************************************************/
/* FEH SDP                                        */
/* Adam Exley, Lauren Pokonosky, Pietro Lavezzo   */
/* Connect 4                                      */
/* Clingan 8:00     12/04/20                      */
/* Ver 1.0                                        */
/**************************************************/

//General headers
#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "FEHSD.h"

//Include class headers
#include "AI.h"
#include "Board.h"
#include "Menu.h"
#include "Game.h"
#include "image.h"



#include "logo_b.c"




/*************************************************** Main *****************/

/**
 * Entry point to the application.
 * 
 * @returns status code of program exit
 */

int main() {

    /** Shared game state array. Is updated by the Board class.
     * */
    int game_state[BOARD_ROWS][BOARD_COLUMNS];

    //Turn counter
    int turns = 0;

    int x, y; //Touch locations

    //Create objects of all required classes
    AI ai;
    Board board(game_state);
    Menu menu;
    Game game;

    // LCD.Clear(WHITE);

    // int enabled[] = {WHITE, RED, BLACK, YELLOW, GRAY};
    // Image connect4logo(enabled, 5);
    // connect4logo.Draw(logo_2b, 160, 51, 2, WHITE, false);

    // Sleep(5.0);


    //show main menu at beginning of game
    menu.showMain();


    while(true){ //Loop game forever

        //Clear Proteus Touch buffer
        LCD.ClearBuffer();

        do{
            //get touch location
            waitForInput(x, y); 

            //execute command associated with location based on menu state
            //loop until a selection is chosen that requires a menu to not be displayed
        }while(menu.checkTouchLocation(x, y));




        //after menu is done executing, begin playing game

        //set game to if the user selected single or multiplayer
        game.setSingleplayer(menu.getSingleplayer());

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
            //Clear Proteus Touch buffer
            LCD.ClearBuffer();

            turns++; //increment turn counter

            if(game.isPlayerTurn()){
                //if it's a player's turn, execute this

                do{
                    //Wait for the user to touch a location of the board
                    temp = board.getCurrentColumn();

                    //if the location was the main menu or exit buttons, break out of the game loop
                    if(temp == MAIN_MENU_CALL_VALUE || temp == EXIT_CALL_VALUE){
                        break;
                    }

                }while(!board.isValidMove());

                //if the location was the main menu or exit buttons, break out of the game loop pt. 2
                if(temp == MAIN_MENU_CALL_VALUE || temp == EXIT_CALL_VALUE){
                    break;
                }

                //update the game state with where the move was made
                board.updateGameState(game.getCurrentPlayer(), game_state);

            }
            else{ //if it's not a player's turn, let the AI pick a move

                // ai.PickMove(game_state);

                do{
                  
                    board.getAIMove(ai.pickMove(game_state));

                }while(!board.isValidMove());
                
                board.updateGameState(2, game_state);

            }

            board.dropChip(game.getCurrentPlayer());

            board.DrawBoard();
            game.switchPlayer();
            

        }while(!board.checkWin());

        //If there was a menu call, address that first 
        
        if(temp == MAIN_MENU_CALL_VALUE){
            menu.showMain();
        }else if(temp == EXIT_CALL_VALUE){
            menu.showExit();
        }else{
            //Otherwise there is a win/loss/tie

            //update in-game statistics
            menu.updateStats(board.checkWin(), turns);

            //Show win/loss screen
            menu.showWinLoss(board.checkWin());

            //reset game
            game.reset();
            board.reset(game_state);

            
            //Player either clicks Exit or Return button at win/loss screen
            menu.checkTouchLocation(x, y); 

        
        }

    }

    return 0;
}

