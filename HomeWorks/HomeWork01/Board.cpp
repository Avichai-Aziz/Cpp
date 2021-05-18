

#include "Board.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// colors of the points in the board
const char  colors[8] = {' ', '.', '+', '*', '/', '\\', '|', '-'};

// constructor
Board::Board(string name, int rows, int cols){
    this->name = name;
    this->rows = rows;
    this->cols = cols;
    this->nextBoard = NULL;
    this->matrix = new char*[cols];
    for(int i = 0; i < rows; i++)
    {
        this->matrix[i] = new char[cols];
    }

    // Initialize a background to the board when created
    for(int j = 0; j < rows; j++)
    {
        for(int k = 0; k < cols; k++)
        {
            this->matrix[j][k] = colors[0];
        }
    }
}

// functions:
// ----------------------------------------------------------------------
// getters and setter functions
string Board::getName(){
    return this->name;
}

int Board::getRows(){
    return this->rows;
}

int Board::getCols(){
    return this->cols;
}

Board* Board::getNextBoard(){
    return this->nextBoard;
}

char** Board::getMatrix(){
    return this->matrix;
}

void Board::setNextBoard(Board* newBoard){
    this->nextBoard = newBoard;
}
// ----------------------------------------------------------------------

// others functions:
// ----------------------------------------------------------------------
// create (x,y) point in the board
void Board::plot(int x, int y, int color){
// pivot Y- rows, pivot X- columns, checking if the point(x,y) is in the board
    if((y >= 0) && (x >= 0) && (y < getRows()) && (x < getCols()))
    {
        this->matrix[y][x] = colors[color];
    }
}

// create the line
void Board::line(int x1, int y1, int x2, int y2, int color){
    bool    plotYX = false;
    int     dx = 0;
    int     dy = 0;
    int     sy = 0;
    int     e = 0;
    int     x = 0;
    int     y = 0;

    // algorithm Bresenham for drawing a line
    if (abs(x2 - x1) < abs(y2 - y1))
    {
        swap(x1,y1);
        swap(x2,y2);
        plotYX = true;
    }
    if(x2 < x1) {
        swap(x1,x2);
        swap(y1,y2);
    }
    dx = (x2 - x1);
    dy = abs(y2 - y1);
    if((y2 - y1) > 0)
    {
        sy = 1;
    }
    else if((y2 - y1) < 0)
    {
        sy = -1;
    }
    else{
        sy = 0;
    }
    e = -dx;
    x = x1;
    y = y1;
    while(x <= x2)
    {
        if(plotYX)
        {
            plot(y, x, color);
        }
        else{
            plot(x, y, color);
        }
        x += 1;
        e += (2 * dy);
        if(e > 0)
        {
            y += sy;
            e -= (2 * dx);
        }
    }
}

// create 8 points - for the circle
void Board::plotCircle(int cX, int cY, int x, int y, int color){
    // create the 4 points: (cX+x,cY+y), (cX+x,cY-y), (cX-x,cY+y), (cX-x,cY-y)
    plot(cX+x,cY+y,color);
    plot(cX+x,cY-y,color);
    plot(cX-x,cY+y,color);
    plot(cX-x,cY-y,color);

    // create the 4 points: (cX+y,cY+x), (cX+y,cY-x), (cX-y,cY+x), (cX-y,cY-x)
    plot(cX+y,cY+x,color);
    plot(cX+y,cY-x,color);
    plot(cX-y,cY+x,color);
    plot(cX-y,cY-x,color);
}

// create the circle
void Board::circle(int cX, int cY, int r, int color){
    int     x = 0;
    int     y = 0;
    int     d = 0;

    // algorithm Bresenham for drawing a circle
    x = 0;
    y = r;
    d = 3 - 2 * r;
    plotCircle(cX, cY, x, y, color);
    while(y >= x)
    {
        x += 1;
        if (d > 0)
        {
            y -= 1;
            d += 4 * (x - y) + 10;
        }
        else {
            d += 4 * x + 6;
        }
        plotCircle(cX, cY, x, y, color);
    }
}

// fill the board
void Board::fill(int x, int y, int color){
    if((y < 0) || (x < 0) || (y >= getRows()) || (x >= getCols()) || (getMatrix()[y][x] != colors[0]))
    {
        return;
    }

    // algorithm Flood fill for filling areas
    plot(x, y, color);
    fill(x+1, y, color);
    fill(x-1, y, color);
    fill(x, y+1, color);
    fill(x, y-1, color);
}

// checking the color of this point
int Board::colorPoint(int x, int y){

    for(int color = 0; color < 8; color++)
    {
        if(getMatrix()[y][x] == colors[color])
        {
            return color;
        }
    }
    return 0;
}

// create a stamp on the board
void Board::stamp(int x, int y, Board* boardStamp){ //x,y is the points on the board we want to print on
    for(int i = 0; i < boardStamp->getRows(); i++)
    {
        for(int j = 0; j < boardStamp->getCols(); j++)
        {
            plot(x+j, y+i, boardStamp->colorPoint(j, i)); // x+j and y+i to print ob the board all the stamp
        }
    }
}
// ----------------------------------------------------------------------