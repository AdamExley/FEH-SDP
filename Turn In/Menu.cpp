/** @file Menu.cpp
 *  @brief Contains all the definitions for the Menu class.
 *  Declarations are in Menu.h.
 * */
#include "Menu.h"


Menu::Menu()
//Adam Exley
//Set menu_state and all stats to 0 except for fastest_win
:menu_state(0), single_player_wins(0), AI_wins(0), fastest_win(999),
 multi_player_1_wins(0), multi_player_2_wins(0)
{}


bool Menu::checkTouchLocation(int x, int y){
    //Adam Exley and Lauren Pokonosky

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

    }
    else{//Not in main menu
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

    //This line should never get reached
    return false;
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



void Menu::showStats(){
    //Lauren Pokonosky

    menu_state = 3; //Set menu_state to stats menu

    LCD.Clear();

    LCD.SetFontColor(TEXT_COLOR);

    LCD.WriteAt("Statistics Data", 100, 20);
        

    LCD.WriteAt("Against AI:", 10, 50);
        LCD.WriteAt("Wins: ", 35, 70);
        LCD.WriteAt(single_player_wins, 125, 70);
        LCD.WriteAt("Losses: ", 35, 90);
        LCD.WriteAt(AI_wins, 125, 90);
    
        LCD.WriteAt("Fastest Win:", 35, 110);
            LCD.WriteAt(fastest_win, 140, 110);
            LCD.WriteAt("    Moves", 155, 110);
    
    LCD.WriteAt("2 Player:", 10, 140);
        LCD.WriteAt("Player 1 Wins:", 35, 160);
        LCD.WriteAt(multi_player_1_wins, 150, 160); //THIS NEEDS TO BE CHANGED
        LCD.WriteAt("Player 2 Wins:", 35, 180);
        LCD.WriteAt(multi_player_2_wins, 150, 180); //THIS NEEDS TO BE CHANGED
  
  
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


bool Menu::getDifficulty(){
    //Adam Exley
    return difficulty;
}

bool Menu::getSingleplayer(){
    //Adam Exley
    return singleplayer;
}



void Menu::updateStats(int winner, int turns){
    //Lauren Pokonosky

    //Updates game statistics

    if(turns < fastest_win){
        fastest_win = turns;
    }

    if (singleplayer == true && winner == 1){ //single player win
        single_player_wins = single_player_wins + 1;
    }
    else if (singleplayer == true && winner == 2){ //single player loss
        AI_wins = AI_wins + 1;
    }
    else if (singleplayer != true && winner == 1){ //multi player player 1 win
        multi_player_1_wins = multi_player_1_wins + 1;
    }
    else if (singleplayer != true && winner == 2){ //multi player player 2 win
        multi_player_2_wins = multi_player_2_wins + 1;
    }
}





void Menu::showWinLoss(int winner){
    //Lauren Pokonosky

    menu_state = 7; //set menu state to win/loss screen

    if (singleplayer == true && winner == 1){ //single player win screen
        LCD.Clear();
        LCD.WriteAt("You Won!", 195, 20);
        LCD.WriteAt("is very proud of you.", 160, 75);
        displayTA();
        
        drawReturnExit();
    }
    else if (singleplayer == true && winner == 2){ //single player loss screen
        LCD.Clear();
        LCD.WriteAt("You Lost...", 195, 20);
        LCD.WriteAt("is disappointed in you.", 160, 75);
        displayTA();

        drawReturnExit();
    }
    else if (singleplayer != true && winner == 1){ //multi player player 1 win screen
        LCD.Clear();
        LCD.WriteAt("Player 1 Wins!", 190, 20);
        LCD.WriteAt("is proud of you,", 170, 75);
        LCD.WriteAt("Player 1,", 205, 100);
        LCD.WriteAt("and disappointed in", 160, 125);
        LCD.WriteAt("you, Player 2.", 185, 150);
        displayTA();
        
        drawReturnExit();
    }
    else if (singleplayer != true && winner == 2){ //multi player player 2 win screen
        LCD.Clear();
        LCD.WriteAt("Player 2 Wins!", 195, 20);
        LCD.WriteAt("is proud of you,", 170, 75);
        LCD.WriteAt("Player 2,", 205, 100);
        LCD.WriteAt("and disappointed in", 160, 125);
        LCD.WriteAt("you, Player 1.", 185, 150);
        displayTA();
        
        drawReturnExit();
    }
    else if (winner == 3){ //Tie screen
        LCD.Clear();
        LCD.WriteAt("Tie!", 195 , 20);
        LCD.WriteAt("is indifferent.", 170, 75);
        displayTA();

        drawReturnExit();
    }

}




void Menu::displayTA(){//this function randomizes the TA image that will show up for the win/loss screen
    //Lauren Pokonosky

    int rand_int = RandInt();
    int TA;
    TA = rand_int % 5 + 1;
        switch (TA){
            case 1:{ //display Bridgette
                LCD.WriteAt("Bridgette", 210, 50);
                int bridgette_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN};
                int bridgette_disable[] = {BLACK};
                Image bridgette(BRIDGETTE_FRAME_WIDTH, BRIDGETTE_FRAME_HEIGHT, bridgette_enable, 5, bridgette_disable, 1);
                bridgette.Draw(bridgette_data);
                    break;
            }
            case 2:{ //display Jane
                LCD.WriteAt("Jane", 210, 50);
                int jane_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN, MAROON};
                int jane_disable[] = {BLACK, MAROON};
                Image jane(JANE_FRAME_WIDTH, JANE_FRAME_HEIGHT, jane_enable, 6, jane_disable, 2);
                jane.Draw(jane_data);
                    break;
            }
            case 3:{ //display Bailey
                LCD.WriteAt("Bailey", 210, 50);
                int bailey_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN};
                int bailey_disable[] = {BLACK};
                Image bailey(BAILEY_FRAME_WIDTH, BAILEY_FRAME_HEIGHT, bailey_enable, 5, bailey_disable, 1);
                bailey.Draw(bailey_data);
                    break;
            }
            case 4:{ //display Alex
                LCD.WriteAt("Alex", 210, 50);
                int alex_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN, BLUE};
                int alex_disable[]= {BLACK};
                Image alex(ALEX_FRAME_WIDTH, ALEX_FRAME_HEIGHT, alex_enable, 6, alex_disable, 1);
                alex.Draw(alex_data);
                    break;
            }
            case 5:{ //display Jamie
                LCD.WriteAt("Jamie", 210, 50);
                int jamie_enable[] = {BLACK, WHITE, GRAY, OLIVE, BROWN, MAROON};
                int jamie_disable[] = {BLACK, BROWN};
                Image jamie(JAMIE_FRAME_WIDTH, JAMIE_FRAME_HEIGHT, jamie_enable, 6, jamie_disable, 2);
                jamie.Draw(jamie_data);
                    break;
            }
        }
}




void Menu::showExit(){
    //Lauren Pokonosky

    menu_state = 5; //Set menu_state to exit screen
    
    LCD.Clear();
    LCD.WriteAt("Paul thanks you", 190, 100);
    LCD.WriteAt("for playing!", 190, 120);
    Sleep(2.0);

    int paul_enable[] = {BLACK, WHITE, GRAY, OLIVE, MAROON, CYAN};
    int paul_disable[] = {BLACK, CYAN};
    Image paul(PAUL_FRAME_WIDTH, PAUL_FRAME_HEIGHT, paul_enable, 6, paul_disable, 2);
    paul.Draw(paul_data, 1, false);

    while(true){ //Run forever

    }
}