

#ifndef HW2NEW1_BOARDGAME_H
#define HW2NEW1_BOARDGAME_H


#include "Triangle.h"
#include "Player.h"
#include <iostream>

using namespace std;

// A class of game board, the board have: number of rows, number of columns, number of triangles, matrix of chars,
// array of triangles that each triangle contains checkers/ empty, and array of 2 players
class BoardGame {
private:
    int             nRows;
    int             nCols;
    int             nTriangles; // 24 in the board + 2 in the vertical middle(eaten checkers) + 1 that took out
    char**          board;
    Triangle*       arrTriangles[27];
    Player*         arrPlayers[2];

public:
    // constructor
    BoardGame();

    // destructor
    ~BoardGame();

    // getters:

    // return the number of columns ini the board
    int         getCols() const;

    // return the number of rows in the board
    int         getRows() const;

    // return the number of triangles in the board
    int         getTrianglesAmount() const;

    // return the game board
    char**      getBoard() const;

    // return triangle from the array of triangles
    Triangle*    getTriangle(int index) const;

    // return player from the array of players
    Player*     getPlayer(int index) const;

    // other functions:

    // print the game board
    void        printBoardGame();

    // increment the length of the upper triangles that in the board by 1
    void        incrementUpTrianglesLen();

    // decrement the length of the upper triangles that in the board by 1
    void        decrementUpTrianglesLen();

    // increment the length of the down triangles that in the board by 1
    void        incrementDownTrianglesLen();

    // decrement the length of the down triangles that in the board by 1
    void        decrementDownTrianglesLen();

    // return the max amount checkers from all the upper triangles
    int         maxAmountCheckersUpTriangles();

    // return the max amount checkers from all the down triangles
    int         maxAmountCheckersDownTriangles();

private:
    // setting the number of rows in the board
    void        setRows(int rows);

    // initialize the first checkers(disks) on the board
    void        initFirstCheckers() const;

    // initialize the background and frame of the board game at start and in case the number of rows changed
    void        boardFrameBackground();

    // initialize the triangles on the board
    void        trianglesOnBoard();

    // increment the rows of the board by 1
    void        incrementRow();

    // decrement the rows of the board by 1
    void        decrementRow();
};

#endif //HW2NEW1_BOARDGAME_H
