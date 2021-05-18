

#ifndef HW1_BOARD_H
#define HW1_BOARD_H
#include <iostream>
#include <string>

using namespace std;

// A class of board, each board have: name, number of rows, number of columns, it surface(matrix) that contains chars
// and pointer for it next board in the list
class Board {
private:
    string  name;       // name of the board
    int     rows;       // number of the rows of the board
    int     cols;       // number of the columns of the board
    char**  matrix;     // each point in the board is a char
    Board*  nextBoard;  // the next board in the list

public:
    // constructor - build a board
    Board(string name, int rows, int cols);

    // functions:
    // ----------------------------------------------------------------------
    Board*  getNextBoard();
    string  getName();
    int     getRows();
    int     getCols();
    char**  getMatrix();

    // change the next board to the board in the signature
    void    setNextBoard(Board* newBoard);

    // create a point on the board with specific color by getting point x, point y and color of this point
    void    plot(int x, int y, int color);

    // create line on the board with specific color from start point x1,y1 to end point x2,y2
    void    line(int x1, int y1, int x2, int y2, int color);

    // create 8 points - for the circle
    void    plotCircle(int cX, int cY,int x, int y, int color);

    // create circle with center in point x,y on the board ,with specific color and specific radius
    void    circle(int cX, int cY, int r, int color);

    // fill the empty parts on the board with specific color from specific start point x,y
    void    fill(int x, int y, int color);

    // create a stamp on the board from other board that in the list
    void    stamp(int x, int y, Board* boardStamp);

    // return the color of this specific x,y point
    int     colorPoint(int x, int y);
    // ----------------------------------------------------------------------
};




#endif //HW1_BOARD_H
