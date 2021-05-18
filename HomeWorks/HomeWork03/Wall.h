

#ifndef HW3_WALL_H
#define HW3_WALL_H

#include <iostream>
#include "Vector2D.h"

// A class of wall, each wall have: point1, point2 and pointer for the next wall in the list
class Wall {
private:
    Vector2D    vPoint1;
    Vector2D    vPoint2;
    Wall*       nextWall;

public:
    // constructor
    Wall(double x1, double y1, double x2, double y2);

    // getters:

    // return the point1 (x1, y1) vector of the wall
    Vector2D    getPoint1() const;
    // return the point2 (x2, y2) vector of the wall
    Vector2D    getPoint2() const;
    // return the next wall that the current wall point to
    Wall*       getNextWall() const;

    // setters:

    // set the point1 vector of the wall
    void        setPoint1(Vector2D newPoint1);
    // set the point2 vector of the wall
    void        setPoint2(Vector2D newPoint2);
    // set the next wall
    void        setNextWall(Wall* newNextWall);
};


#endif //HW3_WALL_H
