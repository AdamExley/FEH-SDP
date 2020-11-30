#include "FEHLCD.h"
#include "AI.h"
#include "Chip.h"
#include "Board.h"

/*
screen is 320 by 240
*/

#define BUTTON_COLOR LCD.Scarlet
#define TEXT_COLOR LCD.White

/**
 * @brief Makes program idle until a touch is detected
 * @param x address to store x coord of touch
 * @param y address to store y coord of touch
 * @returns Nothing
 * */
void waitForInput(int *x, int *y);
/** 
 * @brief Makes program idle until a touch is detected
 * @param x variable to store x coord of touch
 * @param y variable to store y coord of touch
 * @returns Nothing
 * */
void waitForInput(int &x, int &y);

/** Displays all menus for game
 *  Stores current menu state
 * */
class Menu{
    private:
        /** Stores current menu state
         *  
         *  0 - Main
         *  1 - Play
         *  2 - Stats
         *  3 - Instructions
         *  4 - Credits
         *  5 - Exit
         * */
        int menu_state;

        /** @author Lauren Pokonosky
         *  @brief Draws return and exit buttons
         * */
        void drawReturnExit();

    public:

        /** @author Adam Exley
         *  @brief Constructs a Menu object. Sets menu_state to be 0.
         * */
        Menu();

        /** @author Lauren Pokonosky
         *  @brief Displays main menu
         * */
        void showMain();

        /** @author Lauren Pokonosky
         *  @brief Displays game selection menu
         * */
        void showPlay();

        /** @author Lauren Pokonosky
         *  @brief Displays statistics on screen
         * */
        void showStats();

        /** @author Lauren Pokonosky
         *  @brief Displays game instructions
         * */
        void showInstructions();

        /** @author Lauren Pokonosky
         *  @brief Displays the credits for the game
         * */
        void showCredits();

        /** @author Lauren Pokonosky
         *  @brief Displays an exit screen thanking the user for playing
         * */
        void showExit();

        /** @author Adam Exley
         *  @brief Executes the function associated with a certain touch location
         *  @param x X-location of touch
         *  @param y Y-location of touch
         *  @returns True/false corresponding as to if the menu selection should continue looping
         * */
        bool checkTouchLocation(int x, int y);

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

    int x, y;

    //show main menu at beginning of game
    menu.showMain();

    do{
        //get touch location
        waitForInput(x, y); 

        //execute command associated with location based on menu state
        //loop until a selection is chosen that requires a menu to not be displayed
    }while(menu.checkTouchLocation(x, y));

    return 0;
}




void waitForInput(int &x, int &y){
    //Written by Adam Exley
    //Version for variable input
    //Do nothing until touch is registered
    while(!LCD.Touch(&x, &y)); 
}

void waitForInput(int *x, int *y){
    //Adam Exley
    //Version for address input
    //Do nothing until touch is registered
    while(!LCD.Touch(x, y)); 
}



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

    menu_state = 3; //Set menu_state to stats menu

    LCD.Clear();

    LCD.SetFontColor(TEXT_COLOR);

    LCD.WriteAt("Statistics Data", 100, 20);

    LCD.WriteAt("Against AI:", 10, 50);
        LCD.WriteAt("Wins: ", 35, 70);
            LCD.WriteAt("0", 125, 70);
        LCD.WriteAt("Losses: ", 35, 90);
            LCD.WriteAt("0", 125, 90);
        LCD.WriteAt("Fastest Win:", 35, 110);
            LCD.WriteAt("10", 140, 110);
            LCD.WriteAt("   Moves", 155, 110);
    
    LCD.WriteAt("2 Player:", 10, 140);
        LCD.WriteAt("Player 1 Wins:", 35, 160);
        LCD.WriteAt("Player 2 Wins:", 35, 180);
  
  
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

