

#include "Disc.h"

Disc::Disc(double x, double y, double vx, double vy, double r): vPoint(x, y), vVelocity(vx, vy), r(r),
                            m(c * (r * r)), nextDisc(NULL), counterClashed(0), isClashed(false), type("Disc"){}

Disc::Disc(Disc* other){
    vPoint = (other->getPoint());
    vVelocity = (other->vVelocity);
    r = other->getRadius();
    m = other->getMass();
    nextDisc = NULL;
    counterClashed = other->getCounterClashed();
    isClashed = other->getIsClashed();
    type = other->getType();
}

Disc::~Disc() {}

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

bool Disc::getIsClashed() const{
    return this->isClashed;
}

int Disc::getCounterClashed() const {
    return this->counterClashed;
}

std::string Disc::getType() const {
    return this->type;
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
    if(radius > 0){this->r = radius;}
}

void Disc::setMass(double mass) {
    if(mass >0){this->m = mass;}
}

void Disc::setNextDisc(Disc *newNextDisc) {
    this->nextDisc = newNextDisc;
}

void Disc::setIsClashed(bool flag) {
    this->isClashed = flag;
}

void Disc::setCounterClashed(int number) {
    this->counterClashed = number;
}

void Disc::setType(const std::string& newType) {
    this->type = newType;
}

// other functions:

bool Disc::isDiscsClash(Disc& other) const{
    Vector2D     tempVec;

    // algorithm
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

    // algorithm to find the closest point
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

    // algorithm
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

    // algorithm
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

    // algorithm
    closePoint = closestPoint(wall.getPoint1(), wall.getPoint2());
    d = (getPoint() - closePoint);
    d = (d / (Vector2D::norma(d.getX(), d.getY()))); // normalized direction of collision
    vVelocity -=  (d * 2 * (vVelocity * d));
}

void Disc::incCounterClashed() {
    counterClashed++;
}
