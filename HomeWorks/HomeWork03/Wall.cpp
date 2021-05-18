

#include "Wall.h"

Wall::Wall(double x1, double y1, double x2, double y2): vPoint1(x1, y1), vPoint2(x2, y2), nextWall(NULL){}

Vector2D Wall::getPoint1() const {
    return vPoint1;
}

Vector2D Wall::getPoint2() const {
    return vPoint2;
}

Wall *Wall::getNextWall() const {
    return nextWall;
}

void Wall::setPoint1(Vector2D newPoint1) {
    this->vPoint1 = newPoint1;
}

void Wall::setPoint2(Vector2D newPoint2) {
    this->vPoint2 = newPoint2;
}

void Wall::setNextWall(Wall *newNextWall) {
    this->nextWall = newNextWall;
}



