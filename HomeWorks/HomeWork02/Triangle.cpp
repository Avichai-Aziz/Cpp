

#include "Triangle.h"

// constructor

Triangle::Triangle(){
    this->nLength = 5;
    this->nCheckersAmount = 0;
    this->nIndex = 0;
    this->sign = '|';
    this->isBlack = false;
    this->isWhite = false;
    this->chars = new char[getLength()];
    for(int i = 0; i < getLength(); i++)
    {
        this->chars[i] = getSign();
    }
}

// destructor

Triangle::~Triangle() {
    delete[] chars;
}

// getters:

int Triangle::getLength() const{
    return this->nLength;
}

int Triangle::getCheckersAmount() const{
    return this->nCheckersAmount;
}

int Triangle::getTriangleIndex() const{
    return this->nIndex;
}

char Triangle::getSign() const{
    return this->sign;
}

char* Triangle::getChars() const{
    return this->chars;
}

bool Triangle::getIsBlack() const{
    return this->isBlack;
}

bool Triangle::getIsWhite() const{
    return this->isWhite;
}

string Triangle::getColorInside() const{
    if(getIsWhite()){return "White";}
    else if(getIsBlack()){return "Black";}
    return "Empty";
}

char Triangle::getColorChar() const {
    if(isBlack){return 'B';}

    else if(isWhite){return 'W';}

    return getSign();
}

// setters:

void Triangle::setLength(int length){
    if(length > 5)
    {
        this->nLength = length;
    }
    else{
        this->nLength = 5;
    }
}

void Triangle::setCheckersAmount(int amount){
    if(amount >= 0)
    {
        this->nCheckersAmount = amount;
    }
    if(getCheckersAmount() > getLength())
    {
        checkLength();
    }
}

void Triangle::setTriangleIndex(int index){
    if(index >= 0)
    {
        this->nIndex = index;
    }
}

void Triangle::setTriangleSign(char ch){
    this->sign = ch;
}

void Triangle::setChars(char ch, int checkersAmount){
    setCheckersAmount(checkersAmount);
    this->chars = new char[getLength()];
    for (int i = 0; i < getLength(); i++)
    {
        if (i < checkersAmount)
        {
            getChars()[i] = ch;
        }
        else {
            getChars()[i] = getSign();
        }
    }
}

void Triangle::setIsBlack(bool flag){
    this->isBlack = flag;
}

void Triangle::setIsWhite(bool flag){
    this->isWhite = flag;
}

// other functions:

void Triangle::printTriangle() const{
    for(int i = 0; i < getLength(); i++)
    {
        cout << getChars()[i] << endl;
    }
}

void Triangle::incrementCheckers() {
    if ((getCheckersAmount() >= 0) && (getCheckersAmount() < 15))
    {
        this->nCheckersAmount++;
    }
}

void Triangle::decrementCheckers(){
    if ((getCheckersAmount() > 0) && (getCheckersAmount() <= 15))
    {
        this->nCheckersAmount--;
    }
}

bool Triangle::isEmpty() const{
    if((getCheckersAmount() == 0))
    {
        return true;
    }
    return false;
}

// private function:

void Triangle::checkLength(){
    if(getCheckersAmount() > 5)
    {
        setLength(getCheckersAmount());
    }
    else{
        setLength(5);
    }
}
