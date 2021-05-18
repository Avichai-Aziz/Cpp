
#include <iostream>
#include <string>
#include <cstdlib>
#include "BoardList.h"

using namespace std;

//---------------------------------------------------------------------------
//                  			       Coding
//                  			       ------
//
// General : Build a graphical program that can draw lines and circles
//           as well as fill in areas and print the end result in characters.
//
// Input   : (standard input/ text file) Enter command from the specifics commands and the features of the boards,
//           "quit" to end the program.
//
// Process : Add board to the list with its features
//
// Output  : (standard output) Prints board from the list
//---------------------------------------------------------------------------
// Programmer : Avichai Aziz
// Date       : 30.03.2021
//---------------------------------------------------------------------------

// functions:
// -----------------------------------------------------------------------------------------------
// final func that destructor the list - whether an Error occurred or the program gets to an end
void destructList(BoardList boardList){
    if(boardList.listSize() > 0)
    {
        boardList.destructorList();
    }
}

// check order input - function
void checkCommandInput(string command, BoardList boardList){
    if((command != "board") && (command != "plot") && (command != "line") && (command != "circle") && (command != "fill") &&
       (command != "stamp") && (command != "print") && (command != "quit"))
    {
        cerr << "unknown command '" << command << "'" << endl;
        destructList(boardList);
        exit(1);
    }
}

// check name input - function
void checkNameInput(string name, BoardList boardList) {

    //check if the first letter is English letter
    if(!(isalpha(name[0])))
    {
        cerr << "Invalid board name '" << name << "'" << endl;
        destructList(boardList);
        exit(2);
    }

    // check the other letter - must be digit or char
    else {
        for (unsigned int i = 1; i < name.length(); i++)
        {
            if(!(isalpha(name[i]) || (isdigit(name[i]))))
            {
                cerr << "Invalid board name '" << name << "'" << endl;
                destructList(boardList);
                exit(2);
            }
        }
    }
}

// check rows/cols input - function
void checkRowColsInput(int rows, int cols, BoardList boardList) {
    if(rows <= 0 || cols <= 0)
    {
        cerr << "Board: number of rows and columns must be greater that zero" << endl;
        destructList(boardList);
        exit(3);
    }
}

// check color input - function
void checkColorInput(int color, BoardList boardList) {
    if((color < 0) || (color > 7))
    {
        cerr << "Invalid color number " << color << endl;
        destructList(boardList);
        exit(4);
    }
}

// check radius input - function
void checkRadiusInput(int radius, BoardList boardList){
    if(radius < 0)
    {
        cerr << "Circle: radius must be non-negative" << endl;
        destructList(boardList);
        exit(5);
    }
}

// check exists board input - function
void checkExistsBoard(BoardList boardList, string boardName){
    if(!(boardList.existsBoardFunc(boardName)))
    {
        cerr << "Board named '" << boardName << "' not found" << endl;
        destructList(boardList);
        exit(6);
    }
}
// -----------------------------------------------------------------------------------------------


int main() {
    // define variables
    string      command;
    string      boardName;
    string      stampName;
    int         nRows = 0;
    int         nCols = 0;
    int         nX = 0;
    int         nY = 0;
    int         nColor = 0;
    int         nX1 = 0;
    int         nY1 = 0;
    int         nX2 = 0;
    int         nY2 = 0;
    int         nCx = 0;
    int         nCy = 0;
    int         nR = 0;
    BoardList   boardList;
    Board*      board;

    while(cin >> command)
    {
        // checking command input
        checkCommandInput(command, boardList);

        if(command == "board") {
            cin >> boardName >> nRows >> nCols;

            // checking board values input
            checkNameInput(boardName, boardList);
            checkRowColsInput(nRows, nCols, boardList);
            if(boardList.existsBoardFunc(boardName)) // if the board already exists - delete prev and add the new
            {
                boardList.deleteBoardFunc(boardName);
                boardList.addBoardFunc(boardName, nRows, nCols);
            }
            else{
                boardList.addBoardFunc(boardName, nRows, nCols);
            }
        }

        else if(command == "plot")
        {
            cin >> boardName >> nX >> nY >> nColor;

            // checking plot values input
            checkNameInput(boardName, boardList);
            checkExistsBoard(boardList, boardName);
            checkColorInput(nColor, boardList);

            board = boardList.findBoardFunc(boardName);
            board->plot(nX, nY, nColor);
        }

        else if(command == "line")
        {
            cin >> boardName >> nX1 >> nY1 >> nX2 >> nY2 >> nColor;

            // checking line values input
            checkNameInput(boardName, boardList);
            checkExistsBoard(boardList, boardName);
            checkColorInput(nColor, boardList);

            board = boardList.findBoardFunc(boardName);
            board->line(nX1, nY1, nX2, nY2, nColor);
        }

        else if(command == "circle")
        {
            cin >> boardName >> nCx >> nCy >> nR >> nColor;

            // checking circle values input
            checkNameInput(boardName, boardList);
            checkExistsBoard(boardList, boardName);
            checkRadiusInput(nR, boardList);
            checkColorInput(nColor, boardList);

            board = boardList.findBoardFunc(boardName);
            board->circle(nCx, nCy, nR, nColor);
        }

        else if(command == "fill")
        {
            cin >> boardName >> nX >> nY >> nColor;

            // checking fill values input
            checkNameInput(boardName, boardList);
            checkExistsBoard(boardList, boardName);
            if(nColor == 0) {
                cerr << "FloodFill: cannot flood with the background color" << endl;
                exit(4);
            }
            else{
                checkColorInput(nColor, boardList);
            }

            board = boardList.findBoardFunc(boardName);
            board->fill(nX, nY, nColor);
        }

        else if(command == "stamp")
        {
            cin >> boardName >> nX >> nY >> stampName;

            // checking stamp values input
            checkNameInput(boardName, boardList);
            checkNameInput(stampName, boardList);
            checkExistsBoard(boardList, boardName);
            checkExistsBoard(boardList, stampName);

            board = boardList.findBoardFunc(boardName);
            board->stamp(nX, nY, boardList.findBoardFunc(stampName));
        }

        else if(command == "print")
        {
            cin >> boardName;

            checkExistsBoard(boardList, boardName);
            board = boardList.findBoardFunc(boardName);
            // The printing part
            for(int i = 0; i < board->getRows(); i++)
            {
                for(int j = 0; j < board->getCols(); j++)
                {
                    cout << board->getMatrix()[i][j];
                }
                cout << endl;
            }
        }

        else if (command == "quit")
        {
            break;
        }
    }
    destructList(boardList);

    return 0;
}
