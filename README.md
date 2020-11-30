# README
FEH Software Design Project - Connect4

Pietro Lavezzo, Adam Exley, Lauren Pokonosky

## File Structure

Header files are used, [here's a reference on how they work.](https://www.learncpp.com/cpp-tutorial/header-files/)

**.h** files contain the *declarations* of classes and associated functions.

**.cpp** files contain the *definitions* of all functions in the corresponding *.h* file.

**main.cpp** contains all the basic code for the project, as in any other simple program.

## Classes and Functions
*Italics* indicate that the class/function has yet to be implemented.

### AI
- ***AI()***
- ***PickMove()***
- ***PickRandom()***

### Board
- **Board()** - Constructs the board with all spaces set to be blank
- **DrawNewBoard()** - Draws an empty board
- **checkWin()** - Using the game_state array, checks if any 4 chips are in a row
- ***updateGameState(*** column ***)***
- ***isValidMove(*** column ***)***

### Chip
- ***Chip()***
- ***drop(*** column ***)***

### *Menu* 
- **Menu()**
- **showMain()**
- **showPlay()**
- **showStats()**
- **showInstructions()**
- **showCredits()**
- ***playerSelect()***

### Class-less Functions
- **waitForInput(** int *x, int *y ***OR*** int &x, int &y **)** - Waits for and returns location of a touch on the screen
- ***displayWin()***
- ***displayloss()***
- ***switchPlayer()***

## Compiling code
As long as you have the [Proteus Simulator](https://feh.osu.edu/simulator/) installed, compilation is simple.

1. Download the code as a *.zip* file (the green code button)
2. Unzip this file (usually right click -> Extract All/ Unzip)
3. Open the resulting folder in Visual Studio
4. Run *mingw32-make* in the terminal
5. Using the Proteus Simulator, run the resulting *game* file



This file uses markdown syntax. For more information, see https://www.markdownguide.org/basic-syntax/.
