
#ifndef HW4_CONTINUEDHW3_DISC_H
#define HW4_CONTINUEDHW3_DISC_H

#include <iostream>
#include <cmath>
#include "Vector2D.h"
#include "Wall.h"

// const number, to calculate the mass
const double c = 2;

// A class of disc, each disc have: point location, velocity, radius, mass and pointer for the next disc in the list
class Disc {
private:
    Vector2D        vPoint; // the location point of the disc
    Vector2D        vVelocity; // the velocity of thr disc (cm per sec)
    double          r; // radius of disc (cm)
    double          m; // mass of disk (grams), m = (c * r^2), c is a const double that determined by density and thickness
    Disc*           nextDisc; // the next disc in the list
    int             counterClashed;

protected:
    // true if the disc has been clashed, false otherwise
    bool            isClashed;
    // the type of this disc
    std::string     type;
public:
    // constructor: gets x point, y point, velocity x, velocity y, radius
    Disc(double x, double y, double vx, double vy, double r);
    // copy constructor: gets disc pointer
    explicit Disc(Disc* other);
    // destructor
    virtual ~Disc();

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
    // return true if this disc clashed(disc with disc or disc with wall), false otherwise
    virtual bool        getIsClashed() const;
    // return the counter of collisions
    virtual int         getCounterClashed() const;
    // return the type of the disc
    virtual std::string getType() const;

    // setters:

    // set the point vector of disc
    void    setPoint(Vector2D newPoint);
    // set the velocity vector of disc
    void    setVelocity(Vector2D newVelocity);
    // set the radius of the disc
    void    setRadius(double radius);
    // set the mass of the disc
    void    setMass(double mass);
    // set the next disc
    void    setNextDisc(Disc* newNextDisc);
    // set the clash field
    void    setIsClashed(bool flag);
    // set the type of the disc
    void    setType(const std::string& newType);
    // set the number of times disc was clashed
    virtual void    setCounterClashed(int number);


    // other functions:

    // return true whether two discs clash, false otherwise
    bool    isDiscsClash(Disc& disc) const;
    // return true whether disc clash a wall, false otherwise
    bool    isDiscClashWall(Wall& wall) const ;
    // return the closest point of segment p2=(x2,y2) ,p1=(x1,y1), to point p=(x,y)
    Vector2D    closestPoint(Vector2D point1, Vector2D point2) const;

    // update the location of all discs with Δt time  y += vy*Δt ,x += vx*Δt
    void    updateDiscLocation(double deltaT);
    // update the velocity of this disc and the other disc after clash
    void    updateDiscVelocityClashOtherDisc(Disc& other);
    // update the velocity of disc after clash into a wall
    void    updateDiscVelocityClashWall(Wall& wall);
    // increment the counter of clashed by 1
    virtual void    incCounterClashed();

};


#endif //HW4_CONTINUEDHW3_DISC_H
