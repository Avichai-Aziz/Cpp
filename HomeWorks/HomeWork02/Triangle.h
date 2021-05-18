
#ifndef HW2NEW1_TRIANGLE_H
#define HW2NEW1_TRIANGLE_H

#include <iostream>

using namespace std;

// A class of triangle, the triangle is the place where the checkers are on board, each one has: length, index,
// checkers amount, sign, chars(array of signs), if the triangle have black checkers or white checkers.
// there is 27 triangles total - 24 on board, 2 for the eaten checkers of each player and 1 for the checkers that out.
class Triangle {
private:
    int     nLength;
    int     nIndex;
    int     nCheckersAmount;
    char    sign;
    char*   chars;
    bool    isBlack;
    bool    isWhite;

public:
    // constructor
    Triangle();

    // destructor
    ~Triangle();

    // getters:

    // return the length of the triangle
    int     getLength() const;

    // return the checkers(disks) amount in the amount
    int     getCheckersAmount() const;

    // return the index of the triangle
    int     getTriangleIndex() const;

    // return on char that the triangle made of (the char is: '|')
    char    getSign() const;

    // return all the chars that the triangle made of (its the shape/form of the triangle)
    char*   getChars() const;

    // return true if the triangle containing black checkers(disks), otherwise false
    bool    getIsBlack() const;

    // return true if the triangle containing white checkers(disks), otherwise false
    bool    getIsWhite() const;

    // return the color checkers that inside the triangle, if there is no checkers return "Empty"
    string    getColorInside() const;

    // return the color of the triangle as a char: "Black" - 'B' , "White" - 'W'
    char      getColorChar() const;

    // setters:

    // setting the length of the triangle
    void    setLength(int length);

    // setting the index of the triangle
    void    setTriangleIndex(int index);

    // set the amount of checkers in the triangle
    // and check the length of the triangle in relation of checkers amount
    void    setCheckersAmount(int amount);

    // setting the char sign of the triangle
    void    setTriangleSign(char ch);

    // setting all the chars signs of the shape of the triangle
    void    setChars(char ch, int checkersAmount);

    // setting the flag whether there is black checkers in the triangle or not
    void    setIsBlack(bool flag);

    // setting the flag whether there is white checkers in the triangle or not
    void    setIsWhite(bool flag);

    // other functions:

    // print the shape of the triangle
    void    printTriangle() const;

    // increment the amount of the checkers in the triangle by 1
    void    incrementCheckers();

    // decrement the amount of the checkers in the triangle by 1
    void    decrementCheckers();

    // return true if the triangle have no checkers(disks) in it, false otherwise
    bool    isEmpty() const;

private:
    // check the length of the triangle in accordance of the number of the checkers(disks) in the triangle
    // and change it if necessary
    void    checkLength();
};


#endif //HW2NEW1_TRIANGLE_H
