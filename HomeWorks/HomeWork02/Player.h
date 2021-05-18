
#ifndef HW2NEW1_PLAYER_H
#define HW2NEW1_PLAYER_H

#include <iostream>
#include <string>

using namespace std;

// A class of a player, each player have: amount of checkers, color, name and if it his turn now.
class Player {
private:
    int     nAmountCheckers;
    char    color;
    string  name;
    bool    isMyTurn;

public:
    // constructor
    Player(const string& name, char color);

    // getters:

    // return the amount checkers(disks) of this player
    int     getAmountCheckers() const;

    // return the color checkers(disks) of this player
    char    getColor() const;

    // returns true if the turn is of this player, otherwise false
    bool    getIsMyTurn() const;

    //return the name of the player
    string  getName() const;

    // setter:

    //setting whether its this player turn or not
    void    setIsMyTurn(bool flag);

    // other functions:

    // decrement the amount checkers(disks) of the this player by 1
    void    decrementCheckers();

    // print the indexes of the upper triangles from the perspective of this player - 12...1
    static void    printUpperIndexTriangles();

    // print the indexes of the down triangles from the perspective of this player - 13...24
    static void    printDownIndexTriangles();
};

#endif //HW2NEW1_PLAYER_H
