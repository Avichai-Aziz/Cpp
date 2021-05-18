

#include "Player.h"

// constructor

Player::Player(const string& name, char color) {
    this->nAmountCheckers = 15;
    this->color = color;
    this->name = name;
    this->isMyTurn = false; /// need to check if this filed need to be as a variable in the board game or in the main instead of here
}

// getters:

int Player::getAmountCheckers() const {
    return this->nAmountCheckers;
}

char Player::getColor() const {
    return this->color;
}

bool Player::getIsMyTurn() const {
    return this->isMyTurn;
}

string Player::getName() const{
    return this->name;
}

// setter:

void Player::setIsMyTurn(bool flag){
    this->isMyTurn = flag;
}

// other functions:

void Player::printUpperIndexTriangles() {

    cout << " 12 11 10  9  8  7     6  5  4  3  2  1" << endl;
}

void Player::printDownIndexTriangles() {

    cout << " 13 14 15 16 17 18    19 20 21 22 23 24" << endl;
}

void Player::decrementCheckers() {
    if ((getAmountCheckers() > 0) && (getAmountCheckers() <= 15))
    {
        this->nAmountCheckers--;
    }
}
