

#include "BoardList.h"
#include <cstdlib>

using namespace std;

// constructor
BoardList::BoardList() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}

// functions:
// ----------------------------------------------------------------------
int BoardList::listSize(){
    int     counterBoards = 0;

    curr = head;
    while(curr != NULL)
    {
        counterBoards++;
        curr = curr->getNextBoard();
    }
    return counterBoards;
}

// add the board to the linked list
void BoardList::addBoardFunc(string boardName, int rows, int cols){
    Board*  newBoard = new Board(boardName, rows, cols);
    newBoard->setNextBoard(NULL);

    if(head != NULL)
    {
        curr = head;
        while(curr->getNextBoard() != NULL)
        {
            curr = curr->getNextBoard();
        }
        curr->setNextBoard(newBoard);
    }
    else{
        head = newBoard;
    }
}

void BoardList::printBoards(){
    if(listSize() > 0)
    {
        curr = head;
        while (curr != NULL)
        {
            cout << curr->getName() << endl;
            curr = curr->getNextBoard();
        }
    }
    else{
        cout << "None boards" << endl;
    }
}

// find the require board and return it
Board* BoardList::findBoardFunc(string boardName){
    curr = head;

    while(curr != NULL)
    {
        if(curr->getName() == boardName)
        {
            return curr;
        }
        curr = curr->getNextBoard();
    }
    curr = NULL;
    return curr;
}

// delete the required board
void BoardList::deleteBoardFunc(string boardName) {
    Board* delBoard = NULL;
    temp = head;
    curr = head;

    while((curr != NULL) && (curr->getName() != boardName))
    {
        temp = curr;
        curr = curr->getNextBoard();
    }
        if(curr == NULL)
        {
            delete delBoard;
        }
        else{
            delBoard = curr;
            curr = curr->getNextBoard();
            temp->setNextBoard(curr);
            if(delBoard == head)
            {
                head = head->getNextBoard();
                temp = NULL;
            }
            delete delBoard;
        }
}

// check if the required board exists
bool BoardList::existsBoardFunc(string boardName) {
    curr = head;

    while(curr != NULL)
    {
        if(curr->getName() == boardName)
        {
            return true;
        }
        curr = curr->getNextBoard();
    }
    return false;
}

// destruct the list
void BoardList::destructorList(){
    curr = head;
    while(curr != NULL)
    {
        head = head->getNextBoard();
        delete curr;
        curr = head;
    }
}
// ----------------------------------------------------------------------







