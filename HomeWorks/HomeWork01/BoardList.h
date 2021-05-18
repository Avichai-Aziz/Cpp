

#ifndef HW1_BOARDLIST_H
#define HW1_BOARDLIST_H
#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

// A class of linked list that contains boards
class BoardList {
// fields part
private:
    Board*     head;    // the first board in the list
    Board*     curr;    // the current board in the list
    Board*     temp;    // a temp board in the list

public:
    // constructor - build a linked list of boards
    BoardList();

    // functions:
    // ----------------------------------------------------------------------
    // initialize the board add the board to the list
    void    addBoardFunc(string name, int rows, int cols);

    // delete a board from the list
    void    deleteBoardFunc(string boardName);

    // print all the boards in the list
    void    printBoards();

    // check if the specific board is in the list
    bool    existsBoardFunc(string boardName);

    // return the size of the list
    int     listSize();

    // find the specific board in the list and return this board, if not found return NULL
    Board*  findBoardFunc(string boardName);

    // delete all the boards in the list and destruct the list
    void    destructorList();
    // ----------------------------------------------------------------------
};

#endif //HW1_BOARDLIST_H
