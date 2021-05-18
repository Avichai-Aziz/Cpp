

#ifndef HW2NEW1_GAME_H
#define HW2NEW1_GAME_H

#include "BoardGame.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// A class of game, contains all the rules of the game,
// manages the entire game, includes rules of the game, a method that automatically checks if the player can make a move,
// start method of the game.
class Game {
private:
    Player*         playerPtr;
    BoardGame       boardGame;
    unsigned int    X;  // number for the random rolling dice - used in the "Linear congruential generator" algorithm

public:
    // constructor
    explicit Game(int seed);

    // function that start(run) the game
    void    run();

private:

    // algorithm for the random dice:
    // return number for the random rolling dices - Linear congruential generator algorithm
    unsigned int seedFunc();

    // print which one of the players begins
    void printWhoBegins(int whiteDice, int blackDice);

    // return true if the number in dice came out double - equal in values, false otherwise
    bool checkDouble(int firstDice, int secondDice);

    //  if its the White player turn, it flip the indexes to match the indexes of the board game
    int flipNum(int number);

    // check if cin input is failed, if failed - exit(2) from program
    void checkIfCinFail();

    // check if the player can eat the another player,
    // (only if in the destination triangle there is 1 checkers of the another player)
    bool canEat(int to);

    // return true if one of the players wins the game
    bool victory();

    // return true if everything went legal according to the rules
    bool isRulesOk(int from, int to, int firstDice, int secondDice);

    // check automatically if the player have moves to made
    bool isLegalMove(int diceNum);

    // the rules:

    // return true if 'from' and 'to' is out of bounds and print error message, false otherwise
    bool isOutOfBound(int from, int to);

    // return true if there is captured pieces and print error message, false otherwise
    bool isCapturedPiece(int from);

    // return true if trying to move but 'from' is empty and print error message, false otherwise
    bool isFromEmpty(int from);

    // return true if trying to move but there is 2 or more disks from the other player in the 'to' triangle
    // and print error message, false otherwise
    bool isMoreThenOneAtTo(int to);

    // return true if all checkers at home, false otherwise
    bool isAllCheckersHome();

    // return true if the dice number is higher then the 1...6 indexes of triangles,
    // help function to check whether the checkers can take out if all at home and the dice number is higher then index
    bool diceIsHigherThenIndex(int diceNum);

};


#endif //HW2NEW1_GAME_H
