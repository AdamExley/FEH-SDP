#include "FEHLCD.h"
#include "AI.h"
#include "Chip.h"
#include "Board.h"

/*
screen is 320 by 240
*/


void waitForInput(int *x, int *y);
void waitForInput(int &x, int &y);
/*Makes program idle until a touch is detected.
  Returns x and y coords of a touch.
  Overloaded to accept variables or addresses of variables
*/

class Menu{
    private:
        //menu_state: Stores current menu
        /*  0 - Main
            1 - Play
            2 - Stats
            3 - Instructions
            4 - Credits
            5 - Exit
        */
        int menu_state;

    public:
        Menu();
        void showMain();
        void showPlay();
        void showStats();
        void showInstructions();
        void showCredits();
        void showExit();
        bool checkTouchLocation(int x, int y);
        //Returns whether the menu should look for more inputs

};







/**
 * Entry point to the application.
 * 
 * @returns status code of program exit
 */

int main() {
    AI ai;
    Chip chip;
    Board board;
    Menu menu;

    //board.DrawNewBoard();

    int x, y;

    menu.showMain();

    do{

    waitForInput(x, y); 

    }while(menu.checkTouchLocation(x, y));
    




    // //Play Button
    // if (40<=x && x<=140 && 50<=y && y<=100)
    // {
    //     menu.showPlay();

    //     waitForInput(x,y);

    //     //single player mode statement
    //     if (40<=x && x<=150 && 150<=y && y<=200)
    //     {
    //     //Code for Single Player mode
    //     } //end if for single player

    //     //multi-player mode statement
    //     else if (185<=x && x<=296 && 150<=y && y<=200)
    //     {
    //     //code for Multi Player mode
    //     }//end if for multi player

    //     //code for Exit Button
    //     else if (210<=x && x<=300 && 210<=y && y<=234)
    //     {
    //     menu.showExit();
    //     }//end else if for Exit Button

    //     //code for return button
    //     else if (10<=x && x<=140 && 210<=y && y<=234)
    //     {
    //     //Code for return button
    //     }//end else if for return button

    // } //end if for Play Button

 
    // //Statistics Button
    // else if (185<=x && x<=285 && 50<=y && y<=100)
    // {
    // menu.showStats();

    // waitForInput(x,y);
    // } //end if for statistics button

    // //Instructions Button
    // else if (40<=x && x<=140 && 145<=y && y<=195)
    // {
    //   menu.showInstructions();
    //     waitForInput(x,y);
    // } //end else if for Instructions Button

    // //************************************************
    // //Credits Button
    // else if (185<=x && x<=285 && 145<=y && y<=195)
    // {
    // menu.showCredits();
    // waitForInput(x,y);

    // } //end else if for Credits Button

}




void waitForInput(int &x, int &y){
    //Written by Adam Exley
    //Version for variable input
    //Do nothing until touch is registered
    while(!LCD.Touch(&x, &y)); 
}

void waitForInput(int *x, int *y){
    //Written by Adam Exley
    //Version for address input
    //Do nothing until touch is registered
    while(!LCD.Touch(x, y)); 
}



Menu::Menu()
//Constructor
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
        else{//All other buttons
            //So far, only the play menu has other options

            /**********************Add in here*/
            return true;

        }
        
    }
    
}






void Menu::showMain(){
    //Lauren Pokonosky

    menu_state = 0; //Set menu_state to main menu

    //Clear screen
    LCD.Clear();

    LCD.SetDrawColor(LCD.Scarlet);

    //Play Rectangle
    LCD.FillRectangle(40,50,100,50);

    //Statistics Rectangle
    LCD.FillRectangle(185,50,100,50);

    //Instructions Rectangle
    LCD.FillRectangle(40,145,100,50);

    //Credits Rectangle
    LCD.FillRectangle(185,145,100,50);

    LCD.SetFontColor(LCD.White);
    LCD.WriteAt("Play", 75, 55);
    LCD.WriteAt("Game Here", 45, 78);
    LCD.WriteAt("Statistics", 200, 65);
    LCD.WriteAt("Instructions", 45, 165);
    LCD.WriteAt("Credits", 210, 165);

}


void Menu::showPlay(){
    //Lauren Pokonosky

    menu_state = 1; //Set menu_state to play menu
    LCD.Clear();

    LCD.SetDrawColor(LCD.Scarlet);

    //Single Player Rectangle
    LCD.FillRectangle(40,110,110,50);

    //Multi-Player Rectangle
    LCD.FillRectangle(185,110,110,50);

    //Writing button names
    LCD.SetFontColor(LCD.White);
    LCD.WriteAt("Choose a game mode:", 80, 20);
    LCD.WriteAt("Single Player", 45, 125);
    LCD.WriteAt("Multi Player", 195, 125);

    //Return and Exit Button
    LCD.SetDrawColor(LCD.Scarlet);

    LCD.FillRectangle(10, 210, 130, 24); //Return Button
    LCD.FillRectangle(210, 210, 90, 24); //Exit Button

    LCD.WriteAt("Return to Menu", 13, 213);
    LCD.WriteAt("Exit Game", 215, 213);

}

void Menu::showStats(){
    //Lauren Pokonosky

    menu_state = 3; //Set menu_state to stats menu

    LCD.Clear();

    LCD.WriteAt("Statistics Data", 100, 20);
  
    //Return and Exit Button
    LCD.SetDrawColor(LCD.Scarlet);

    LCD.FillRectangle(10, 210, 130, 24); //Return Button
    LCD.FillRectangle(210, 210, 90, 24); //Exit Button

    LCD.WriteAt("Return to Menu", 13, 213);
    LCD.WriteAt("Exit Game", 215, 213);
}

void Menu::showCredits(){
    //Lauren Pokonosky

    menu_state = 4; //Set menu_state to credits menu

    LCD.Clear();

    LCD.WriteAt("Game Created By:", 0, 0);
    LCD.WriteAt("Pietro Lavezzo", 0, 30);
    LCD.WriteAt("Adam Exley", 0, 60);
    LCD.WriteAt("Lauren Pokonosky", 0, 90);
  
    //Return and Exit Button
    LCD.SetDrawColor(LCD.Scarlet);

    LCD.FillRectangle(10, 210, 130, 24); //Return Button
    LCD.FillRectangle(210, 210, 90, 24); //Exit Button

    LCD.WriteAt("Return to Menu", 13, 213);
    LCD.WriteAt("Exit Game", 215, 213);
}

void Menu::showInstructions(){
    //Lauren Pokonosky

    menu_state = 3; //Set menu_state to instructions menu

    LCD.Clear();

    LCD.WriteAt("Connect Four Rules:", 0, 0);
    LCD.WriteAt("The object of the game is to be the first", 0, 30);
    LCD.WriteAt("player to place chips that make a", 0, 60);
    LCD.WriteAt("perfect row or diagonal line of four.", 0, 90); 
    LCD.WriteAt("Take turns clicking the column that", 0, 120);
    LCD.WriteAt("you want to drop the chip into.", 0, 150);

    //Return and Exit Button
    LCD.SetDrawColor(LCD.Scarlet);

    LCD.FillRectangle(10, 210, 130, 24); //Return Button
    LCD.FillRectangle(210, 210, 90, 24); //Exit Button

    LCD.WriteAt("Return to Menu", 13, 213);
    LCD.WriteAt("Exit Game", 215, 213);
}

void Menu::showExit(){
    //Lauren Pokonosky

    menu_state = 5; //Set menu_state to exit screen

    LCD.Clear();
    LCD.WriteAt("Thank you for playing!", 80, 115);
}
