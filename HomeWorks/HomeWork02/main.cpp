#include <iostream>
#include <cstdlib>
#include "Game.h"

//--------------------------------------------------------------------------------------------
//                  			       Coding
//                  			       ------
//
// General : Build the backgammon game.
//           The program allow the game between two human players,
//           while enforcing its rules.
//
// Input   : Movement on board game according to the dices number.
//
// Process : Rolling dice and moving checkers(discs).
//
// Output  : (standard output) The board of the game in each turn, until one of players wins.
//--------------------------------------------------------------------------------------------
// Programmer : Avichai Aziz
// Date       : 21.04.2021
//--------------------------------------------------------------------------------------------
//
//                  example of starting point: Black player begins
//                 ------------------------------------------------
//                      12 11 10  9  8  7     6  5  4  3  2  1
//                    +------------------+-+------------------+
//                    + W  |  |  |  B  | + + B  |  |  |  |  W +
//                    + W  |  |  |  B  | + + B  |  |  |  |  W +
//                    + W  |  |  |  B  | + + B  |  |  |  |  | +
//                    + W  |  |  |  |  | + + B  |  |  |  |  | +
//                    + W  |  |  |  |  | + + B  |  |  |  |  | +
//                    +                  + +                  +
//                    + B  |  |  |  |  | + + W  |  |  |  |  | +
//                    + B  |  |  |  |  | + + W  |  |  |  |  | +
//                    + B  |  |  |  W  | + + W  |  |  |  |  | +
//                    + B  |  |  |  W  | + + W  |  |  |  |  B +
//                    + B  |  |  |  W  | + + W  |  |  |  |  B +
//                    +------------------+-+------------------+
//                      13 14 15 16 17 18    19 20 21 22 23 24
//


// check if cin input is failed, if failed - exit(2) from program
void checkIfCinFail(){
    if(cin.fail())
    {
        cout << "Missing user input - quiting game." << endl;
        exit(2);
    }
}

int main() {
    int     nSeed = 0; // for the random number generator

    // input the seed number
    cout << "Enter seed" << endl;
    cin >> nSeed;
    // check if the the input failed
    checkIfCinFail();

    Game game(nSeed);
    game.run();

    return 0;
}
