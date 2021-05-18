

#include "BoardGame.h"

using namespace std;

// constructor

BoardGame::BoardGame() : arrTriangles(),  arrPlayers() {

    this->nCols = 41;
    this->nTriangles = 27;
    this->board = new char*[nCols];
    for(int i = 0; i < nTriangles; i++) //create 27 triangles
    {
        this->arrTriangles[i] = new Triangle;
    }
    this->nRows = (arrTriangles[1]->getLength() + arrTriangles[13]->getLength()+3); // 1 row middle space + 2 frame rows
    this->arrPlayers[0] = new Player("White", 'W'); // white player
    this->arrPlayers[1] = new Player("Black", 'B'); // black player
    boardFrameBackground();
    initFirstCheckers();
    trianglesOnBoard();
}

// destructor

BoardGame::~BoardGame() {

    for(int i = 0; i < getTrianglesAmount(); i++)
    {
        delete arrTriangles[i];
    }
    delete arrPlayers[0];
    delete arrPlayers[1];
    for(int i = 0; i < getRows(); i++)
    {
        delete[] board[i];
    }
    delete board;
}

// getters:

int BoardGame::getCols() const {
    return this->nCols;
}

int BoardGame::getRows() const {
    return this->nRows;
}

int BoardGame::getTrianglesAmount() const {
    return this->nTriangles;
}

Triangle* BoardGame::getTriangle(int index) const{
    if((index >=0) && (index <= 27))
    {
        return arrTriangles[index];
    }
    return NULL;
}

Player* BoardGame::getPlayer(int index) const{
    if((index == 0) || (index == 1))
    {
        return arrPlayers[index];
    }
    return NULL;
}

char** BoardGame::getBoard() const{
    return this->board;
}

// other functions:

void BoardGame::printBoardGame(){
    boardFrameBackground();
    trianglesOnBoard();
    for(int i = 0; i < getRows(); i++)
    {
        for(int j = 0; j < getCols(); j++)
        {
            cout << getBoard()[i][j];
        }
        cout << endl;
    }
}

void BoardGame::incrementUpTrianglesLen(){
    incrementRow();
    for(int i = 1; i <= 12; i++)
    {
        arrTriangles[i]->setLength((arrTriangles[i]->getLength()) + 1);
        arrTriangles[i]->getChars()[arrTriangles[i]->getLength() - 1] = arrTriangles[i]->getSign();
    }
    arrTriangles[26]->setLength((arrTriangles[26]->getLength()) + 1);
    arrTriangles[26]->getChars()[(arrTriangles[26]->getLength()) - 1] = arrTriangles[26]->getSign();
}

void BoardGame::decrementUpTrianglesLen(){
    for(int i = 1; i <= 12; i++)
    {
        arrTriangles[i]->setLength((arrTriangles[i]->getLength()) - 1);
    }
    arrTriangles[26]->setLength((arrTriangles[26]->getLength()) - 1);
    decrementRow();
}

void BoardGame::incrementDownTrianglesLen(){
    incrementRow();
    for(int i = 13; i <= 25; i++)
    {
        arrTriangles[i]->setLength((arrTriangles[i]->getLength()) + 1);
        arrTriangles[i]->getChars()[(arrTriangles[i]->getLength()) - 1] = arrTriangles[i]->getSign();
    }
}

void BoardGame::decrementDownTrianglesLen(){
    for(int i = 13; i <= 25; i++)
    {
        arrTriangles[i]->setLength((arrTriangles[i]->getLength()) - 1);
    }
    decrementRow();
}

int BoardGame::maxAmountCheckersUpTriangles(){
    int     maxAmountCheckers = arrTriangles[26]->getCheckersAmount();
    int     tempNum = 0;
    for(int i = 1; i <= 12; i++)
    {
        tempNum = arrTriangles[i]->getCheckersAmount();
        maxAmountCheckers >= tempNum ? maxAmountCheckers = maxAmountCheckers : maxAmountCheckers = tempNum;
    }
    return maxAmountCheckers;
}

int BoardGame::maxAmountCheckersDownTriangles(){
    int     maxAmountCheckers = arrTriangles[13]->getCheckersAmount();
    int     tempNum = 0;
    for(int i = 14; i <= 25; i++)
    {
        tempNum = arrTriangles[i]->getCheckersAmount();
        maxAmountCheckers >= tempNum ? maxAmountCheckers = maxAmountCheckers : maxAmountCheckers = tempNum;
    }
    return maxAmountCheckers;
}

// private function:

void BoardGame::setRows(int rows) {
    if((rows >= 13) && (rows <= 33))
    {
        this->nRows = rows;
    }
}

void BoardGame::initFirstCheckers() const{
    char    whiteColor = 'W';
    char    blackColor = 'B';
    // Initialize the first checkers on the board game
    for(int i = 0; i < getTrianglesAmount(); i++)  // start from index 1 cause index 0 is the checkers that took out
    {
        getTriangle(i)->setTriangleIndex(i);
        if(i == 0)
        {
            getTriangle(i)->setIsBlack(true);
            getTriangle(i)->setIsWhite(true);
        }
        else if(i == 1)
        {
            getTriangle(i)->setChars(whiteColor, 2);
            getTriangle(i)->setIsWhite(true);
        }
        else if(i == 6)
        {
            getTriangle(i)->setChars(blackColor, 5);
            getTriangle(i)->setIsBlack(true);
        }
        else if(i == 8)
        {
            getTriangle(i)->setChars(blackColor, 3);
            getTriangle(i)->setIsBlack(true);
        }
        else if(i == 12)
        {
            getTriangle(i)->setChars(whiteColor, 5);
            getTriangle(i)->setIsWhite(true);
        }
        else if(i == 13)
        {
            getTriangle(i)->setChars(blackColor, 5);
            getTriangle(i)->setIsBlack(true);
        }
        else if(i == 17)
        {
            getTriangle(i)->setChars(whiteColor, 3);
            getTriangle(i)->setIsWhite(true);
        }
        else if(i == 19)
        {
            getTriangle(i)->setChars(whiteColor, 5);
            getTriangle(i)->setIsWhite(true);
        }
        else if(i == 24)
        {
            getTriangle(i)->setChars(blackColor, 2);
            getTriangle(i)->setIsBlack(true);
        }
        else if(i == 25) // its the vertical middle in the down board - belong to the black eaten checkers(disks)
        {
            getTriangle(i)->setTriangleSign(' ');
            getTriangle(i)->setChars(blackColor, 0);
            getTriangle(i)->setIsBlack(true);
        }
        else if(i == 26) // its the vertical middle in the upper board - belong to the white eaten checkers(disks)
        {
            getTriangle(i)->setTriangleSign(' ');
            getTriangle(i)->setChars(whiteColor, 0);
            getTriangle(i)->setIsWhite(true);
        }
    }
}

void BoardGame::boardFrameBackground(){
    for(int i = 0; i < getRows(); i++)
    {
        this->board[i] = new char[getCols()];
    }

    // Initialize a background to the board
    for(int row = 0; row < getRows(); row++)
    {
        for (int col = 0; col < getCols(); col++)
        {
            this->board[row][col] = ' ';
        }
    }

    // Initializes the frame of the board
    for(int i = 0; i < getRows(); i++)
    {
        for(int j = 0; j < getCols(); j++)
        {
            if((j == 0) || (j == (getCols()-1)) || ((j == ((getCols()-1) / 2) - 1)) || ((j == ((getCols()+3) / 2) - 1)))
            {
                getBoard()[i][j] = '+';
            }

            else if(((i == 0) || (i == (getRows()-1))) && (j < (getCols()-1)) && (j > 0))
            {
                getBoard()[i][j] = '-';
            }
        }
    }
}

void BoardGame::trianglesOnBoard(){
    int     trianglesIndexUp = 12;
    int     trianglesIndexDown = 13;

    // Initialize the upper board with triangles
    for(int col = 0; col < getCols(); col++)
    {
        if((col % 3) == 2)
        {
            for(int row = 1; row <= getTriangle(1)->getLength(); row++)
            {
                if(col == ((getCols()-1)/2))
                {
                    this->board[row][col] = getTriangle(26)->getChars()[row-1];
                }
                else{
                    this->board[row][col] = getTriangle(trianglesIndexUp)->getChars()[row-1];
                }
            }
            if(col != ((getCols()-1)/2)){ trianglesIndexUp--;}
        }
    }

    // Initialize the down board with triangles
    for(int col = 0; col < getCols(); col++)
    {
        int     index = ((getTriangle(13)->getLength())-1); // index of the chars in the triangle chars
        if(((col % 3) == 2) && (col != ((getCols()-1)/2)))
        {
            for(int row = getTriangle(1)->getLength()+2; row < (getRows()-1); row++)
            {
                this->board[row][col] = getTriangle(trianglesIndexDown)->getChars()[index];
                index--;
            }
            trianglesIndexDown++;
        }
        else if(col == ((getCols()-1)/2))
        {
            for(int row = getTriangle(1)->getLength()+2; row < (getRows()-1); row++)
            {
                this->board[row][col] = getTriangle(25)->getChars()[index];
                index--;
            }
        }
    }
}

void BoardGame::incrementRow(){
    // include the frame(2) + middle space(1)
    // if all 15 checkers(disks) of one player are in a certain triangle and 15 checkers of the other player
    // are in a second triangle, each in a different side of the board then the number of rows will be 33
    if((getRows() >= 13) && (getRows() < 33))
    {
        setRows(++this->nRows);
    }
}

void BoardGame::decrementRow(){
    // include the frame(2 rows) + middle space(1 row)
    // if all 15 checkers(disks) of one player are in a certain triangle and 15 checkers of the other player
    // are in a second triangle, each in a different side of the board then the number of rows will be 33
    if((getRows() > 13) && (getRows() <= 33))
    {
        setRows(--this->nRows);
    }
}
