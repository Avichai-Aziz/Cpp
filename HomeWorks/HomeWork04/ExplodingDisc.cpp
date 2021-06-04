
#include "ExplodingDisc.h"

ExplodingDisc::ExplodingDisc(double x, double y, double vx, double vy, double r): Disc(x, y, vx, vy, r),
                            counterClashed(0) {type = "Exploding_Disc";}

ExplodingDisc::~ExplodingDisc() {}

int ExplodingDisc::getCounterClashed() const {
    return this->counterClashed;
}

bool ExplodingDisc::getIsClashed() const{
    return this->isClashed;
}

void ExplodingDisc::setCounterClashed(int number) {
    this->counterClashed = number;
}

void ExplodingDisc::incCounterClashed() {
    counterClashed++;
}
