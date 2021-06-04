

#include "ShrinkingDisc.h"

ShrinkingDisc::ShrinkingDisc(double x, double y, double vx, double vy, double r) :
                                Disc(x, y, vx, vy, r), counterClashed(0) {type = "Shrinking_Disc";}

ShrinkingDisc::~ShrinkingDisc() {}

int ShrinkingDisc::getCounterClashed() const {
    return this->counterClashed;
}

bool ShrinkingDisc::getIsClashed() const{
    return this->isClashed;
}

void ShrinkingDisc::setCounterClashed(int number) {
    this->counterClashed = number;
}

void ShrinkingDisc::incCounterClashed() {
    counterClashed++;
}

