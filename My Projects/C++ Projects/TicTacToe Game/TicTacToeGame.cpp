
// ============================================================
// Tic Tac Toe Game
//
// A simple console-based Tic Tac Toe game where:
//   - The human player uses 'X'
//   - The computer uses 'O'
//   - The computer always chooses the first available square
//
// The game continues until either a player wins or the board
// is completely filled, resulting in a draw.
// ============================================================

#include <iostream>
#include <tuple>
//#if !defined(TicTacToe_H)
//#define TicTacToe_H

class TicTacToeGame
{

public:
    //Constructor and destructor
    TicTacToeGame();
    virtual ~TicTacToeGame();

    // Starts and Controls the entire game loop
    void play();

private:
    // Initializes every board position with '~'
    // to represent an enpty square 
    void initializeGrid();

    // Displays the current game board 
    void displayGrid();

    // Computer move: 
    // Returns the coordinates of the first avaliable square
    std:: tuple<int, int> findFirstUnoccupiedGridSquare();

    // Prompts the user to enter a row and column
    std:: tuple<int, int> promptForGridCoord();

    // Returns true in the board is full
    bool checkForDraw();

    // Returns true if either player has three in a row
    bool checkForWin();

private:
    // Dynamic 3x3 game board
    // '~' = empty
    // 'X' = human
    // 'O' = computer
    char** pp_cGrid = nullptr; // Pointer to (pointer to character)
};

//--------------------------------------------------------------
// Constructor
//
// Allocates memory for a 3x3 game board and initializes every
// square as empty.
//--------------------------------------------------------------

TicTacToeGame::TicTacToeGame() 
{
    this->pp_cGrid = new char* [3] ; // array of three pointer to char

    // Allocate memory for three rows
    for(int iRow = 0; iRow <3; ++iRow)
        pp_cGrid[iRow] = new char[3];

        initializeGrid();
}

//--------------------------------------------------------------
// Destructor
//
// Releases all dynamically allocated memory to prevent leaks.
//--------------------------------------------------------------

TicTacToeGame::~TicTacToeGame()
{
    for(int iRow = 0; iRow <3; ++iRow)
    {
        delete[] pp_cGrid[iRow]; //Delete arrays of 3 characters
    }
    delete[] pp_cGrid; // Delete array of three pointers to character
    pp_cGrid = nullptr;
}

//--------------------------------------------------------------
// initializeGrid()
//
// Sets every board position to '~' to indicate an empty space.
//--------------------------------------------------------------

void TicTacToeGame::initializeGrid()
{
    for (int iRow = 0; iRow < 3; iRow++)
    {
        for(int iColumn = 0; iColumn <3; iColumn++) 
        {
            this->pp_cGrid[iRow][iColumn] = '~';
        }
     }
 }

//--------------------------------------------------------------
// displayGrid()
//
// Prints the current state of the game board.
//--------------------------------------------------------------


 void TicTacToeGame::displayGrid()
 {
    for(int iRow = 0; iRow < 3; iRow++) 
    {
         for(int iColumn = 0; iColumn <3; iColumn++) 
         {
            std::cout<< this->pp_cGrid[iRow][iColumn] << " ";
         }
         std::cout << std::endl;
    }
    std::cout << std::endl;
 }

//--------------------------------------------------------------
// play()
//
// Controls the entire game.
//
// The game alternates between:
//   1. Human player turn
//   2. Computer turn
//
// After every move, the board is checked for a win or draw.
//--------------------------------------------------------------

 void TicTacToeGame::play()
 {
    bool bWin = false;
    bool bDraw = false;
    int iRow = 0;
    int iColumn = 0;

    std::cout << "Tic Tac Toe" << std::endl;
    std::cout << std::endl;

    displayGrid();

    while (!bWin && !bDraw) 
    {

        //Human Player Turn
        std::tie(iRow, iColumn) = promptForGridCoord();
        this->pp_cGrid[iRow][iColumn] = 'X';

        displayGrid();
        bWin = checkForWin();
        bDraw = checkForDraw();
    

        //Computer Player Turn

        if(!bWin and !bDraw) 
        {
            std::tie(iRow, iColumn) = findFirstUnoccupiedGridSquare();
            this->pp_cGrid[iRow][iColumn]= 'O';
            
            displayGrid();
            bWin = checkForWin();
            bDraw = checkForDraw();
        }

        if(bDraw && !bWin)
        {
            std::cout << "Draw!" << std::endl;
        }

    }
    std::cout<<"Game Over."<< std::endl;
    return;

 }

//--------------------------------------------------------------
// promptForGridCoord()
//
// Asks the user to enter the row and column where they wish
// to place their piece.
//
// Returns:
//      (row, column)
//--------------------------------------------------------------

 std::tuple<int, int> TicTacToeGame:: promptForGridCoord()
 {
    int iRow = 0;
    int iColumn = 0;

    std::cout << "Please enter grid row number: " << std::endl;
    std::cin >> iRow;

    std::cout << "Please enter grid column number: " << std::endl;
    std:: cin>> iColumn;

    std::tuple<int, int> tupleCoord = std::make_tuple(iRow, iColumn);

    return tupleCoord;
 }

//--------------------------------------------------------------
// findFirstUnoccupiedGridSquare()
//
// Searches the board from top-left to bottom-right and returns
// the first empty square found.
//
// This serves as the computer's simple AI.
//--------------------------------------------------------------

 std::tuple<int, int> TicTacToeGame::findFirstUnoccupiedGridSquare()
 {
    int iRowUnoccupied = -1;
    int iColumnUnoccupied = -1;
    
    bool bFound = false;

    for(int iRow = 0; (iRow <3)&& !bFound; iRow++)
    {
        for(int iColumn = 0; (iColumn < 3)&& !bFound; iColumn++) 
        {
            if (this->pp_cGrid[iRow][iColumn] == '~')
            {
                iRowUnoccupied = iRow;
                iColumnUnoccupied = iColumn;
                bFound = true;
            }
        }
    }
    std::tuple<int, int> tupleUnoccupiedGridSquare(iRowUnoccupied, iColumnUnoccupied);
    return tupleUnoccupiedGridSquare;
 }

 bool TicTacToeGame::checkForDraw()
 {
    bool bContinue = false;

    //Continue game is there are open squares left
    //Otherwise, it mist be a win or a draw

    //Checking the game is in continue mode or not
    for(int iRow = 0; iRow < 3; iRow++)
    {
        for (int iColumn = 0; iColumn < 3; iColumn++)
        {
            if(this->pp_cGrid[iRow][iColumn]!= 'X' && this->pp_cGrid[iRow][iColumn] != 'O')
            bContinue = true;
        }
    }
    return !bContinue;
 }

//--------------------------------------------------------------
// checkForWin()
//
// Checks all possible winning combinations:
//   • Three rows
//   • Three columns
//   • Two diagonals
//
// Returns true if either player has won.
//--------------------------------------------------------------

 bool TicTacToeGame::checkForWin()
 {
    bool bWin = false;
    for(int iRow = 0; (iRow <3) && !bWin; iRow++)
    {
        if (this->pp_cGrid[iRow][0] != '~')
        {
            if ((this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][1]) && (this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][2])) {
                bWin = true;
                std::cout<< "WINNER: " << this->pp_cGrid[iRow][0] << "!" <<
                std::endl;
            }
        }
    }


    // Check Columns
    for(int iColumn = 0; (iColumn<3) && !bWin; iColumn++)
    {
        if(this->pp_cGrid[0][iColumn] != '~') 
        {
            if ((this->pp_cGrid[0][iColumn] == this->pp_cGrid[1][iColumn]) && (this->pp_cGrid[0][iColumn] == this->pp_cGrid[2][iColumn])) {
                bWin = true;
                std::cout<< "WINNER: " << this->pp_cGrid[0][iColumn] << "!" <<
                std::endl;
            }
        }
    }

    // Check main diagonal
    if(this->pp_cGrid[0][0] != '~') 
    {
        if ((this->pp_cGrid[0][0] == this->pp_cGrid[1][1]) && (this->pp_cGrid[0][0] == this->pp_cGrid[2][2])) {
            bWin = true;
            std::cout<< "WINNER: " << this->pp_cGrid[0][0] << "!" <<
            std::endl;
        }
    }

    // Check opposite diagonal
    if(this->pp_cGrid[0][2] != '~') 
    {
        if ((this->pp_cGrid[0][2] == this->pp_cGrid[1][1]) && (this->pp_cGrid[0][2] == this->pp_cGrid[2][0])) {
            bWin = true;
            std::cout<< "WINNER: " << this->pp_cGrid[0][2] << "!" <<
            std::endl;
        }
    }
    return bWin;
 }
 

//--------------------------------------------------------------
// main()
//
// Creates the Tic Tac Toe game, starts it, and frees memory.
//--------------------------------------------------------------

 int main()
{
    TicTacToeGame* p_game = new TicTacToeGame();
    p_game->play();
    delete p_game;
}


//#endif