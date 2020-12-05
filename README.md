# README
FEH Software Design Project - Connect4

Pietro Lavezzo, Adam Exley, Lauren Pokonosky

## Compiling Code and Running Connect 4
As long as you have the [Proteus Simulator](https://feh.osu.edu/simulator/) installed, compilation is simple.

1. Download the code as a *.zip* file (the green code button)
2. Unzip this file (usually right click -> Extract All/ Unzip)
3. Open the resulting folder in Visual Studio
4. Run *mingw32-make* in the terminal
5. Using the Proteus Simulator, run the resulting *game* file

## File Structure

Header files are used, [here's a reference on how they work.](https://www.learncpp.com/cpp-tutorial/header-files/)

**.h** files contain the *declarations* of classes and associated functions.

**.cpp** files contain the *definitions* of all functions in the corresponding *.h* file.

**main.cpp** contains all the basic code for the project, as in any other simple program.

## Classes and Functions Used

Brief descriptions provided; see documentation or code for more information.

**Bold** functions are public

### AI
- **AI()** - Constructs AI object
- **setDifficulty()** - Sets AI difficulty
- **pickMove()** - AI makes a move based on the current game state
- easyMove() - A random column is selected as a move
- isValidMove() - Modified from board class
- inARow() - Counts number of playable chip combos in a row given a game state
- fromCenter() - Gives the average dispersion of a player's chips from the center

### Board
- **Board()** - Constructs the board with all spaces set to be blank
- **DrawNewBoard()** - Draws an empty board
- **checkWin()** - Using the game_state array, checks if any 4 chips are in a row
- **updateGameState(** player **)** - Adds a chip to the game_state array with value "player" in the given column
- ***isValidMove(*** column ***)***

### Menu 
- **Menu()** - Constructs menu and sets menu state to be the main menu
- **showMain()** - Draws main menu
- **showPlay()** - Draws game selection menu
- **showStats()** - Draws statistics screen
- **showInstructions()** - Shows game instructions
- **showCredits()** - Shows game credits
- ***AISelect()***

### Class-less Functions
- **waitForInput(** int *x, int *y ***OR*** int &x, int &y **)** - Waits for and returns location of a touch on the screen

