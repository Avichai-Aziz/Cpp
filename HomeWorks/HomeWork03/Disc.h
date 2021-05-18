

#ifndef HW3_DISC_H
#define HW3_DISC_H

#include <iostream>
#include <cmath>
#include "Vector2D.h"
#include "Wall.h"

// const number
const double c = 2;

// A class of disc, each disc have: point location, velocity, radius, mass and pointer for the next disc in the list
class Disc {
private:
    Vector2D    vPoint; // the location point of the disc
    Vector2D    vVelocity; // the velocity of thr disc (cm per sec)
    double      r; // radius of disc (cm)
    double      m; // mass of disk (grams), m = (c * r^2), c is a const double that determined by density and thickness
    Disc*       nextDisc; // the next disc in the list

public:
    // constructor
    Disc(double x, double y, double vx, double vy, double r);

    Disc(Disc& other);

    //getters:

    // return the point vector of disc
    Vector2D    getPoint() const;
    // return the velocity vector of disc
    Vector2D    getVelocity() const;
    // return the radius of the disc
    double      getRadius() const;
    // return the mass of the disc
    double      getMass() const;
    // return the next disc that the current disc point to
    Disc*       getNextDisc() const;

    // setters:

    // set the point vector of disc
    void        setPoint(Vector2D newPoint);
    // set the velocity vector of disc
    void        setVelocity(Vector2D newVelocity);
    // set the radius of the disc
    void        setRadius(double radius);
    // set the next disc
    void        setNextDisc(Disc* newNextDisc);

    // other functions:

    // return true whether discs clash, false otherwise
    bool        isDiscsClash(Disc& disc) const;
    // return the closest point of segment p2=(x2,y2) ,p1=(x1,y1), to point p=(x,y)
    Vector2D    closestPoint(Vector2D point1, Vector2D point2) const;
    // return true whether disc clash a wall, false otherwise
    bool        isDiscClashWall(Wall& wall) const ;

    // update the location of all discs with Δt time  y += vy*Δt ,x += vx*Δt
    void        updateDiscLocation(double deltaT);
    // update the velocity of this disc and the other disc after clash
    void        updateDiscVelocityClashOtherDisc(Disc& other);
    // update the velocity of disc after clash into a wall
    void        updateDiscVelocityClashWall(Wall& wall);
};


#endif //HW3_DISC_H
