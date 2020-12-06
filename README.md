# README
FEH Software Design Project - Connect4

Pietro Lavezzo, Adam Exley, Lauren Pokonosky

Additional documentation can be found on the [offical website](https://u.osu.edu/sdph2020/)

## Compiling Code and Running Connect 4
As long as you have the [Proteus Simulator](https://feh.osu.edu/simulator/) installed, compilation is simple.

1. Download the code as a **.zip** file from the project [GitHub page](https://github.com/AdamExley/FEH-SDP/releases)
2. Unzip this file (usually right click -> Extract All/ Unzip)
3. Open the resulting folder in Visual Studio
4. Run **mingw32-make** in the terminal
5. Using the Proteus Simulator, run the resulting **game** file

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
- **Board()** - Constructs board object
- **Reset()** - Resets object to inital state
- **DrawBoard()** - Draws full board
- **DrawChips()** - Draws only chips of board
- **DrawBoardMenu()** - Draws menu buttons to left of board
- **isValidMove()** - Checks that specified move is valid
- **getCurrentColumn()** - Finds the column that the player selects
- **getAIMove()** - Imports AI move
- **dropChip()** - Animates the dropping of a chip
- occludeChip() - Covers over a dropping chip with an approximation of the board
- **updateGameState()** - Adds new chip to board
- pushGameState() -  Exports internal game state to external array
- **checkWin()** - Checks for a win or tie

### Game
- **Game()** - Constructs object, sets current player to 1
- **Reset()** - Resets current player
- **setSingleplayer()** - Sets if game is single or multiplayer
- **getCurrentPlayer()** - Returns current player ID
- **isPlayerTurn()** - Returns if it is a human's turn
- **switchPlayer()** - Switches current player

Includes the classless function:
- **waitForInput()** - Waits for and returns location of a touch on the screen

### Image
- **Image()** - Constructs an Image object, sets size and options
- **Draw()** - Converts, optimizes, and plots an image from a hexadecimal color array
- lookupColor() - Finds the cloesest Proteus color to a hexadecimal color
- HorizLineOptimize() - Attempts to change small discrepencies in color in lines
- PlotImg() - Displays image on screen

### Menu 
- **Menu()** - Constructs Menu object and sets menu state and statistics
- **checkTouchLocation()** - Waits for a touch and execues the function corresponding to the touch location
- **showMain()** - Draws main menu
- showPlay() - Draws game selection menu
- showDifficulty() - Draws singleplayer difficulty selection screen
- showStats() - Draws statistics screen
- showInstructions() - Shows game instructions
- showCredits() - Shows game credits
- drawReturnExit() - Draws the return and exit buttons present on most menus
- **getDifficulty()** - Returns selected difficulty
- **getSingleplayer()** - Returns if singleplayer mode was selected
- **updateStats()** - Updates stored statistics
- **showWinLoss()** - Shows the win/loss/tie screen
- displayTA() - Draws a random TA for win/loss/tie screens
- **showExit()** - Shows the game exit screen forever


