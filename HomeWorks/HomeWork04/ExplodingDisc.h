

#ifndef HW4_CONTINUEDHW3_EXPLODINGDISC_H
#define HW4_CONTINUEDHW3_EXPLODINGDISC_H

#include "Disc.h"

class ExplodingDisc: public Disc{
    int     counterClashed;

public:
    // constructor: gets x point, y point, velocity x, velocity y, radius
    ExplodingDisc(double x, double y, double vx, double vy, double r);
    // destructor
    virtual ~ExplodingDisc();
    // return the counter of collisions
    virtual int     getCounterClashed() const;
    // return true if this disc clashed(disc with disc or disc with wall), false otherwise
    virtual bool    getIsClashed() const;

    // set the number of times disc was clashed
    virtual void    setCounterClashed(int number);
    // increment the counter of clashed by 1
    virtual void    incCounterClashed();

};


#endif //HW4_CONTINUEDHW3_EXPLODINGDISC_H
