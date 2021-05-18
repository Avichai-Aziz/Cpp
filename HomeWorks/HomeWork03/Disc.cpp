

#include "Disc.h"

Disc::Disc(double x, double y, double vx, double vy, double r): vPoint(x, y), vVelocity(vx, vy), r(r),
            m(c * (r * r)), nextDisc(NULL){}

Disc::Disc(Disc& other){
    other.setPoint(getPoint());
    other.setVelocity(getVelocity());
    other.r = getRadius();
    other.m = getMass();
    other.nextDisc = NULL;
}

// getters:

Vector2D Disc::getPoint() const {
    return vPoint;
}

Vector2D Disc::getVelocity() const {
    return vVelocity;
}

double Disc::getRadius() const{
    return r;
}

double Disc::getMass() const{
    return m;
}

Disc* Disc::getNextDisc() const{
    return nextDisc;
}

// setters:

void Disc::setPoint(Vector2D newPoint) {
    this->vPoint = newPoint;
}

void Disc::setVelocity(Vector2D newVelocity) {
    this->vVelocity.setX(newVelocity.getX());
    this->vVelocity.setY(newVelocity.getY());
}

void Disc::setRadius(double radius) {
    if(radius > 0){this->r = radius;};
}

void Disc::setNextDisc(Disc *newNextDisc) {
    this->nextDisc = newNextDisc;
}

// other functions:

bool Disc::isDiscsClash(Disc& other) const{
    Vector2D     tempVec;

    tempVec = (vPoint - other.getPoint()); // p - p'
    if((Vector2D::norma(tempVec.getX(), tempVec.getY())) <= (getRadius() + other.getRadius())) // ||p - p'|| <= r + r'
    {
        return true;
    }
    return false;
}

Vector2D Disc::closestPoint(Vector2D point1, Vector2D point2) const {
    double      alpha = 0;
    Vector2D    tempVec;

    tempVec = (point1 - point2);
    if(point1 == point2) // segment has length zero
    {
        return point1;
    }
    else{
        alpha = (getPoint() - point1) * (point2 - point1); // it is the dot product operator
        alpha /= pow((Vector2D::norma(tempVec.getX(), tempVec.getY())), 2);
        if(alpha < 0)
        {
            return point1;
        }
        else if(alpha > 1)
        {
            return point2;
        }
        else{
            return (point1 + ((point2 - point1) * alpha));
        }
    }
}

bool Disc::isDiscClashWall(Wall& wall) const {
    Vector2D    tempVec;
    Vector2D    closePoint;

    closePoint = closestPoint(wall.getPoint1(), wall.getPoint2());
    tempVec = (getPoint() - closePoint);
    if((Vector2D::norma(tempVec.getX(), tempVec.getY())) <= getRadius())
    {
        return true;
    }
    return false;
}

void Disc::updateDiscLocation(double deltaT) {
    vPoint.setX((vPoint.getX() + (vVelocity.getX() * deltaT)));
    vPoint.setY((vPoint.getY() + (vVelocity.getY() * deltaT)));
}

void Disc::updateDiscVelocityClashOtherDisc(Disc& other) {
    Vector2D     d;
    Vector2D     delta;
    Vector2D     tempV;

    d = (vPoint - other.getPoint());
    d = (d / (Vector2D::norma(d.getX(), d.getY()))); // normalized direction of collision
    delta = d * ((vVelocity - other.getVelocity()) * d);
    vVelocity -= ((delta) * ((2 * other.getMass()) / (getMass() +  other.getMass())));
    tempV = (other.vVelocity) + ((delta) * ((2 * getMass()) / (getMass() +  other.getMass())));
    other.setVelocity(tempV);
}

void Disc::updateDiscVelocityClashWall(Wall& wall) {
    Vector2D    d;
    Vector2D    closePoint;

    closePoint = closestPoint(wall.getPoint1(), wall.getPoint2());
    d = (getPoint() - closePoint);
    d = (d / (Vector2D::norma(d.getX(), d.getY()))); // normalized direction of collision
    vVelocity -=  (d * 2 * (vVelocity * d));
}



