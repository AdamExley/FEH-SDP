/** @file Menu.cpp
 *  @brief Contains all the definitions for the Menu class.
 * Declarations are in Menu.h.
 * */

#include "Menu.h"
#include "Game.h"



Menu::Menu()
//Adam Exley
//Set menu_state to 0
:menu_state(0)
{}


bool Menu::checkTouchLocation(int x, int y){
    //Adam Exley

    if (!menu_state){ //In main Menu
        //Check each button location in main menu

        if (40<=x && x<=140 && 50<=y && y<=100){//Play Button
            showPlay();
            return true;
        }
        else if (185<=x && x<=285 && 50<=y && y<=100){//Statistics Button
            showStats();
            return true;
        }
        else if (40<=x && x<=140 && 145<=y && y<=195){//Instructions Button
            showInstructions();
            return true;
        }
        else if (185<=x && x<=285 && 145<=y && y<=195){//Credits Button
            showCredits();
            return true;
        }
        else{//No Button on Main Menu was hit
            return true;
        }

    }else{//Not in main menu
        //All other menus feature "Return" and "Exit" buttons
        //Check these buttons first

        if (10<=x && x<=140 && 210<=y && y<=234){//Return button
            //As of now, all screens return to main menu
            showMain();
            return true;
        }
        else if (210<=x && x<=300 && 210<=y && y<=234){//Exit button

            showExit();
            return false;
        }

        if(menu_state == 1 || menu_state == 6){
            //Player and difficulty selection screens have different buttons at the same locations

            if (40<=x && x<=150 && 110<=y && y<=160) {//Left Button

                if(menu_state == 1){ //Player selection
                    //Single Player Button
                    
                    singleplayer = true; //set singleplayer state
                    showDifficulty(); //go to difficulty selection screen
                    
                    return true; //continue looping menu

                }else if (menu_state == 6){ //Difficulty Selection
                    //Easy
                    difficulty = false; //set difficulty

                    LCD.Clear(); //clear screen
                    return false; //stop looping menu
                }
                
            }
            else if (185<=x && x<=295 && 110<=y && y<=160) {//Right Button
            
                if(menu_state == 1){ //Player selection
                    //Single Player Button
                    
                    singleplayer = false; //set singleplayer state

                    LCD.Clear(); //clear screen
                    return false; //stop looping menu

                }else if (menu_state == 6){ //Difficulty Selection
                    //Easy
                    difficulty = true; //set difficulty to hard

                    LCD.Clear(); //clear screen
                    return false; //stop looping menu
                }
            }
        }
    }
}






void Menu::showMain(){
    //Lauren Pokonosky

    menu_state = 0; //Set menu_state to main menu

    //Clear screen
    LCD.Clear();

    LCD.SetDrawColor(BUTTON_COLOR);
    LCD.SetFontColor(TEXT_COLOR);

    //Play Rectangle
    LCD.FillRectangle(40,50,100,50);
    LCD.WriteAt("Play", 75, 55);
    LCD.WriteAt("Game Here", 45, 78);

    //Statistics Rectangle
    LCD.FillRectangle(185,50,100,50);
    LCD.WriteAt("Statistics", 200, 65);

    //Instructions Rectangle
    LCD.FillRectangle(40,145,100,50);
    LCD.WriteAt("Instructions", 45, 165);

    //Credits Rectangle
    LCD.FillRectangle(185,145,100,50);
    LCD.WriteAt("Credits", 210, 165);
}


void Menu::showPlay(){
    //Lauren Pokonosky

    menu_state = 1; //Set menu_state to play menu
    LCD.Clear();

    LCD.SetDrawColor(BUTTON_COLOR);

    //Single Player Rectangle
    LCD.FillRectangle(40,110,110,50);

    //Multi-Player Rectangle
    LCD.FillRectangle(185,110,110,50);

    //Writing button names
    LCD.SetFontColor(TEXT_COLOR);
    LCD.WriteAt("Choose a game mode:", 80, 20);
    LCD.WriteAt("Single Player", 45, 125);
    LCD.WriteAt("Multi Player", 195, 125);

    //Draws Return and Exit buttons 
    drawReturnExit();

}

void Menu::showStats(){
    //Lauren Pokonosky
    
        int single_player_wins = 0, AI_wins = 0, multi_player_1_wins = 0, multi_player_2_wins = 0;

    menu_state = 3; //Set menu_state to stats menu

    LCD.Clear();

    LCD.SetFontColor(TEXT_COLOR);

    LCD.WriteAt("Statistics Data", 100, 20);
        
            if (singleplayer = true && Board.checkWin() = 1){ //single player win
                single_player_wins = single_player_wins + 1;
            }
            else if (singleplayer = true && Board.checkWin() = 2){ //single player loss
                AI_wins = AI_wins + 1;
            }
            else if (singleplayer != true && Board.checkWin() = 1){ //multi player player 1 win
                multi_player_1_wins = multi_player_1_wins + 1;
            }
            else if (singleplayer != true && Board.checkWin() = 2){ //multi player player 2 win
                multi_player_2_wins = multi_player_2_wins + 1;
            }
    
    LCD.WriteAt("Against AI:", 10, 50);
        LCD.WriteAt("Wins: ", 35, 70);
        LCD.WriteAt(single_player_wins, 125, 70);
        LCD.WriteAt("Losses: ", 35, 90);
        LCD.WriteAt(AI_wins, 125, 90);
    
        LCD.WriteAt("Fastest Win:", 35, 110);
            LCD.WriteAt("10", 140, 110);
            LCD.WriteAt("   Moves", 155, 110);
    
    LCD.WriteAt("2 Player:", 10, 140);
        LCD.WriteAt("Player 1 Wins:", 35, 160);
        LCD.WriteAt(multi_player_1_wins, 150, 160); //THIS NEEDS TO BE CHANGED
        LCD.WriteAt("Player 2 Wins:", 35, 180);
        LCD.WriteAt(multi_player_2_wins, 150, 180); //THIS NEEDS TO BE CHANGED
  
  
    //Draws Return and Exit buttons 
    drawReturnExit();
}

void Menu::showCredits(){
    //Lauren Pokonosky

    menu_state = 4; //Set menu_state to credits menu

    LCD.Clear();

    LCD.WriteAt("Game Created By:", 0, 0);
    LCD.WriteAt("Pietro Lavezzo", 0, 30);
    LCD.WriteAt("Adam Exley", 0, 60);
    LCD.WriteAt("Lauren Pokonosky", 0, 90);
  
    //Draws Return and Exit buttons 
    drawReturnExit();
}

void Menu::showInstructions(){
    //Lauren Pokonosky

    menu_state = 3; //Set menu_state to instructions menu

    LCD.Clear();

    LCD.WriteAt("Connect Four Rules:", 0, 0);
    LCD.WriteAt("The object of the game is to be the first", 0, 20);
    LCD.WriteAt("player to place chips that make a", 0, 40);
    LCD.WriteAt("perfect row or diagonal line of four", 0, 60); 

    LCD.WriteAt("Take turns clicking anywhere in the", 0, 90);
    LCD.WriteAt("column that you want to drop your chip", 0, 110);
    LCD.WriteAt("in to try to win!", 0, 130);

    //Draws Return and Exit buttons 
    drawReturnExit();
}

void Menu::showExit(){
    //Lauren Pokonosky

    menu_state = 5; //Set menu_state to exit screen

    LCD.Clear();
    LCD.WriteAt("Thank you for playing!", 80, 115);
}


void Menu::drawReturnExit(){
    //Lauren Pokonosky

    //Draws Return and Exit buttons 
    LCD.SetDrawColor(BUTTON_COLOR);
    LCD.SetFontColor(TEXT_COLOR);

    LCD.FillRectangle(10, 210, 130, 24); //Return Button
    LCD.FillRectangle(210, 210, 90, 24); //Exit Button

    LCD.WriteAt("Return to Menu", 13, 213);
    LCD.WriteAt("Exit Game", 215, 213);
}

void Menu::showDifficulty(){
    
    menu_state = 6; //Set menu_state to difficulty selection
    LCD.Clear();

    LCD.SetDrawColor(BUTTON_COLOR);

    //Easy Rectangle
    LCD.FillRectangle(40,110,110,50);

    //Hard Rectangle
    LCD.FillRectangle(185,110,110,50);

    //Writing button names
    LCD.SetFontColor(TEXT_COLOR);
    LCD.WriteAt("Choose a game difficulty:", 70, 20);
    LCD.WriteAt("Easy", 75, 125);
    LCD.WriteAt("Hard", 220, 125);
    
    //Draws Return and Exit buttons 
    drawReturnExit();
}




bool Menu::getDifficulty(){
    return difficulty;
}

bool Menu::getSingleplayer(){
    return singleplayer;
}

