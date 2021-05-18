

#include "Game.h"

//constructor

Game::Game(int seed) : playerPtr(NULL) , X(seed){}

//private functions:

unsigned int Game::seedFunc(){
    const unsigned int a = 22695477;
    const unsigned int c = 1;
    X = ((a * X) + c);
    return ((((X & 0x7fffffff) >> 16) % 6)+1);
}

void Game::printWhoBegins(int whiteDice, int blackDice){
    if(whiteDice < blackDice)
    {
        cout << "White player casts " << whiteDice << ", black player casts " << blackDice <<
             endl << "Black plays first." << endl;
    }
    else if(whiteDice > blackDice)
    {
        cout << "White player casts " << whiteDice << ", black player casts " << blackDice <<
             endl << "White plays first." << endl;
    }
    else if(whiteDice == blackDice)
    {
        cout << "White player casts " << whiteDice << ", black player casts " << blackDice << endl;
    }
}

bool Game::checkDouble(int firstDice, int secondDice){
    if(firstDice == secondDice){ return true;}
    return false;
}

int Game::flipNum(int number) {
    if(playerPtr->getName() == "White")
    {
        if(number == 25){return 26;}
        else if(number == 26){return 25;}
        else if(number == 0){return 0;}
        return (25-number);
    }
    return number;
}

bool Game::canEat(int to){
    if((boardGame.getTriangle(to)->getCheckersAmount() == 1) && (to != 0))
    {
        if((boardGame.getPlayer(0)->getIsMyTurn()) && (boardGame.getTriangle(to)->getIsBlack())){return true;}
        else if((boardGame.getPlayer(1)->getIsMyTurn()) && (boardGame.getTriangle(to)->getIsWhite())){return true;}
    }
    return false;
}

bool Game::victory(){
    if(playerPtr->getAmountCheckers() == 0)
    {
        cout << playerPtr->getName() << " player wins!" << endl;
        return true;
    }
    return false;
}

// private: exceptions functions:

void Game::checkIfCinFail(){
    if(cin.fail())
    {
        cout << "Missing user input - quiting game." << endl;
        exit(2);
    }
}

bool Game::isOutOfBound(int from, int to){
    int     difference = abs(from - to);
    // means player wants to take out checkers from his capture checkers
    if(from == -1)
    {
        return false;
    }
    if((from > 25) || (from < 1) || (to < 0) || (to > 24) || (difference > 6) || (difference < 1))
    {
        cout << "Illegal move: From/to out of bounds (from=" << from << ", to=" << to << ")." << endl;
        return true;
    }
    return false;
}

bool Game::isCapturedPiece(int from){
    if(playerPtr->getName() == "Black")
    {
        if((from != 25) && (boardGame.getTriangle(25)->getCheckersAmount() >= 1))
        {
            cout << "Illegal move: Player still has captured piece(s)." << endl;
            return true;
        }
        return false;
    }
    else if(playerPtr->getName() == "White")
    {
        if((from != 26) && (boardGame.getTriangle(26)->getCheckersAmount() >= 1))
        {
            cout << "Illegal move: Player still has captured piece(s)." << endl;
            return true;
        }
        return false;
    }
    return false;
}

bool Game::isFromEmpty(int from){
    if(boardGame.getTriangle(from)->isEmpty())
    {
        cout << "Illegal move: No pieces at from location " << flipNum(from) << '.' << endl;
        return true;
    }
    return false;
}

bool Game::isMoreThenOneAtTo(int to){
    if((boardGame.getTriangle(to)->getColorInside() != playerPtr->getName()) &&
        (boardGame.getTriangle(to)->getCheckersAmount() > 1) && (to != 0))
    {
        cout << "Illegal move: Cannot capture more that one piece at location " << flipNum(to) << '.' << endl;
        return true;
    }
    return false;
}

bool Game::isAllCheckersHome(){
    if(playerPtr->getName() == "Black")
    {
        for(int i = 25; i >= 7; i--)
        {
            if(boardGame.getTriangle(i)->getIsBlack()){ return false;}
        }
        return true;
    }
    else if(playerPtr->getName() == "White")
    {
        for(int i = 1; i <= 18; i++)
        {
            if((boardGame.getTriangle(i)->getIsWhite()) || (boardGame.getTriangle(26)->getIsWhite()))
            {
                    return false;
            }
        }
        return true;
        }
    return false;
}

bool Game::diceIsHigherThenIndex(int diceNum) {
    for(int i = 6; i >= 1; i--)
    {
        if(boardGame.getPlayer(1)->getIsMyTurn()) // white turn
        {
            if((boardGame.getTriangle(i)->getIsBlack()) && (diceNum > i))
            {
                return true;
            }

        }
        else if(boardGame.getPlayer(0)->getIsMyTurn()) // white turn
        {
            if((boardGame.getTriangle(flipNum(i))->getIsWhite()) && (diceNum > i))
            {
                return true;
            }
        }
    }
    return false;
}

bool Game::isRulesOk(int from, int to, int firstDice, int secondDice){

    // check if the input of 'from' in range 1..25 and 'to' in range 0..24 and the difference in range 1..6
    if(isOutOfBound(flipNum(from), flipNum(to))){return false;}
    // check if the black player have checkers that captured - his eaten checkers are in the 25th triangle
    else if(isCapturedPiece(from)){return false;}
    // check if the 'from' triangle is empty
    else if(isFromEmpty(from)){return false;}
    // check if there is two or more checkers in the 'to' triangle
    else if(isMoreThenOneAtTo(to)){return false;}
    // check if the player can start taking out checkers from board game
    else if((to == 0) && (!isAllCheckersHome()))
    {
        cout << "Illegal move: Cannot bear off while not all pieces at home." << endl;
        return false;
    }
    // check if the movement that the player want to made equal to the dices number
    else if((flipNum(from) - flipNum(to) != firstDice) && (flipNum(from) - flipNum(to) != secondDice))
    {
        if(isAllCheckersHome() && ((diceIsHigherThenIndex(firstDice)) || (diceIsHigherThenIndex(secondDice))))
        {
            return true;
        }
        cout << "Illegal move: No value of "<< flipNum(from) - flipNum(to) << " in dice roll " << endl;
        return false;
    }
    // check that the player doesn't try to move checkers that is not his color from triangle 'from'
    else if(boardGame.getTriangle(from)->getColorInside() != playerPtr->getName())
    {
        cout << "Illegal move: Can move only " << playerPtr->getName() << " piece(s)." << endl;
        return false;
    }

    return true;
}

bool Game::isLegalMove(int diceNum){
    int     to = (25 - diceNum); //the destination triangle

    if(playerPtr->getName() == "Black")
    {
        // check if player can pull the capture checkers out (to put them in one of the 24..19 indexes  from sight to black)
        if(boardGame.getTriangle(25)->getCheckersAmount() >= 1)
        {
            if((!boardGame.getTriangle(to)->isEmpty()) && (boardGame.getTriangle(to)) &&
                (boardGame.getTriangle(to)->getCheckersAmount() > 1))
            {
                return false;
            }
        }
        else{
            // passes and tries to advance one of the checkers to one of the free triangles or occupied black triangles
            for(int i = 24; i <= 1; i--)
            {
                to = (i - diceNum);
                if((boardGame.getTriangle(i)->getIsBlack()) && (to > 0))
                {
                    if((!boardGame.getTriangle(to)->isEmpty()) && (boardGame.getTriangle(to)->getIsWhite()) &&
                       (boardGame.getTriangle(to)->getCheckersAmount() > 1))
                    {
                        return false;
                    }
                }
                else if((to <= 0) && (!isAllCheckersHome()))
                {
                    return false;
                }
            }
        }
        return true;
    } // end if "Black"

    else if(playerPtr->getName() == "White")
    {
        if(boardGame.getTriangle(26)->getCheckersAmount() >= 1)
        {
            // check if player can pull the capture checkers out (to put them in one of the 24..19 indexes from sight to white)
            if((!boardGame.getTriangle(to)->isEmpty()) && (boardGame.getTriangle(to)->getIsBlack()) &&
                (boardGame.getTriangle(to)->getCheckersAmount() > 1))
            {
                return false;
            }
        }

        else{
            // passes and tries to advance one of the checkers to one of the free triangles or occupied white triangles
            for(int i = 24; i <= 1; i--) ///need to check this one!!
            {
                to = flipNum((i - diceNum)); //the destination triangle
                if((boardGame.getTriangle(flipNum(i))->getIsWhite()) && ((to <= 24) && (to >= 1)) )
                {
                    if((!boardGame.getTriangle(to)->isEmpty()) && (boardGame.getTriangle(to)->getIsBlack()) &&
                       (boardGame.getTriangle(to)->getCheckersAmount() > 1))
                    {
                        return false;
                    }
                }
                else if(((to == 0) || (to >= 25)) && (!isAllCheckersHome()))
                {
                    return false;
                }
            }
        }
        return true;
    }// end if "White"
    return false;
}

//public function:

void Game::run() {
    int     firstDice = 0;
    int     secondDice = 0;
    int     from = 0;
    int     to = 0;
    int     times = 0;
    bool    isDouble = false;
    bool    moveOk = true;
    bool    endGame = false;

    // getting the first dice number to check who begin, if its a tie, it's rolling again the dice
    firstDice = (int)seedFunc(); //white player roll dice
    secondDice = (int)seedFunc(); // black player roll dice
    while(firstDice == secondDice)
    {
        printWhoBegins(firstDice, secondDice);
        firstDice = (int)seedFunc();
        secondDice = (int)seedFunc();
    }

    if(firstDice > secondDice)
    {
        playerPtr = boardGame.getPlayer(0); // White player
    }
    else if(firstDice < secondDice)
    {
        playerPtr = boardGame.getPlayer(1); // Black player
    }
    playerPtr->setIsMyTurn(true);

    printWhoBegins(firstDice, secondDice);

    while(!endGame)
    {
        //printing the board game
        (playerPtr->getName() == "Black")? Player::printUpperIndexTriangles() : Player::printDownIndexTriangles();
        boardGame.printBoardGame();
        (playerPtr->getName() == "White")? Player::printUpperIndexTriangles() : Player::printDownIndexTriangles();

        // rolling dices
        firstDice = (int)seedFunc();
        secondDice = (int)seedFunc();
        isDouble = checkDouble(firstDice, secondDice);
        isDouble ? (times = 4) : (times = 2);

        cout << playerPtr->getName() << " rolls " << firstDice << '-' << secondDice << '.' << endl;

        ///function that check automatically if the player can make moves
        if((!isLegalMove(firstDice)) && (!isLegalMove(secondDice)))
        {
            // print error message whether there is no possible move for the player
            cout << "No possible move for " << playerPtr->getName() << endl;
            times = 0; // the player cannot move checkers
        }

        while(times--)
        {
            if(playerPtr->getIsMyTurn())
            {
                cout << "Enter " << playerPtr->getName() << " move: " << endl;
            }
            cin >> from >> to;
            // check if the the input failed
            checkIfCinFail();

            from = flipNum(from);
            to = flipNum(to);

            if(!isRulesOk(from, to, firstDice, secondDice))
            {
                moveOk = false;
                times++;
            }
            else{
                moveOk = true;
            }

            if(moveOk)
            {
                // decrement checkers(disk) from specific triangle
                boardGame.getTriangle(from)->decrementCheckers();
                // decrement length of all the upper or down triangles
                if(((from >= 1) && (from <= 12)) || (from == 26))
                {
                    if((boardGame.getTriangle(from)->getLength() > boardGame.maxAmountCheckersUpTriangles()) &&
                        boardGame.getTriangle(from)->getLength() > 5)
                    {
                        boardGame.decrementUpTrianglesLen();
                    }
                }
                else if((from >= 13) && (from <= 25))
                {
                    if(boardGame.getTriangle(from)->getLength() > boardGame.maxAmountCheckersDownTriangles() &&
                       boardGame.getTriangle(from)->getLength() > 5)
                    {
                        boardGame.decrementDownTrianglesLen();
                    }
                }

                for(int i = 1; i <= 26; i++)
                {
                    boardGame.getTriangle(i)->setChars(boardGame.getTriangle(i)->getColorChar(), boardGame.getTriangle(i)->getCheckersAmount());
                }


                /// set the checkers with the current amount on the 'from' triangle
                boardGame.getTriangle(from)->setChars(playerPtr->getColor(), boardGame.getTriangle(from)->getCheckersAmount());

                // check if there is checkers(disks) in the 'from' triangle
                if (boardGame.getTriangle(from)->isEmpty())
                {
                    boardGame.getTriangle(from)->setIsBlack(false);
                    boardGame.getTriangle(from)->setIsWhite(false);
                }

                //check eat
                if(canEat(to))
                {
                    boardGame.getTriangle(to)->decrementCheckers();
                    if(playerPtr->getName() == "White")
                    {
                        boardGame.getTriangle(25)->incrementCheckers(); // means that the white player eat black checkers
                        boardGame.getTriangle(25)->setChars(boardGame.getPlayer(1)->getColor(),
                                                            boardGame.getTriangle(25)->getCheckersAmount());
                        boardGame.getTriangle(25)->setIsBlack(true);
                    }
                    else if(playerPtr->getName() == "Black")
                    {
                        boardGame.getTriangle(26)->incrementCheckers(); // means that the black player eat white checkers
                        boardGame.getTriangle(26)->setChars(boardGame.getPlayer(0)->getColor(),
                                                            boardGame.getTriangle(26)->getCheckersAmount());
                        boardGame.getTriangle(26)->setIsWhite(true);
                    }
                }
                // increment checkers(disk) to specific triangle and increment row if necessary
                boardGame.getTriangle(to)->incrementCheckers();
                // increment length of all the upper or down triangles

                if((to >= 1) && (to <= 12))
                {
                    if(boardGame.maxAmountCheckersUpTriangles() > boardGame.getTriangle(to)->getLength())
                    {
                        boardGame.incrementUpTrianglesLen();
                    }
                }
                else if((to >= 13) && (to <= 24))
                {
                    if(boardGame.maxAmountCheckersDownTriangles() > boardGame.getTriangle(to)->getLength())
                    {
                        boardGame.incrementDownTrianglesLen();
                    }
                }

                // set the checkers with the current amount on the 'to' triangle
                boardGame.getTriangle(to)->setChars(playerPtr->getColor(), boardGame.getTriangle(to)->getCheckersAmount());

                // if there is checkers from same color in the specific triangle set the triangle as the color of the player
                if ((boardGame.getTriangle(to)->getCheckersAmount() >= 1) && (to != 0))
                {
                    if(boardGame.getPlayer(0)->getIsMyTurn()) // White turn
                    {
                        boardGame.getTriangle(to)->setIsWhite(true);
                        boardGame.getTriangle(to)->setIsBlack(false);

                    }
                    else if(boardGame.getPlayer(1)->getIsMyTurn()) // Black turn
                    {
                        boardGame.getTriangle(to)->setIsBlack(true);
                        boardGame.getTriangle(to)->setIsWhite(false);
                    }
                }

                // pulling out checkers from the board if true
                if((to == 0) && (isAllCheckersHome()))
                {
                    playerPtr->decrementCheckers();
                }
            }
            playerPtr->getAmountCheckers() == 0 ? (times = 0) : (times = times);
        } // end while (times)

        victory()? (endGame = true) : (endGame = false);
        if(boardGame.getPlayer(0)->getIsMyTurn())
        {
            boardGame.getPlayer(0)->setIsMyTurn(false);
            boardGame.getPlayer(1)->setIsMyTurn(true);
            playerPtr = boardGame.getPlayer(1);
        }
        else if(boardGame.getPlayer(1)->getIsMyTurn())
        {
            boardGame.getPlayer(0)->setIsMyTurn(true);
            boardGame.getPlayer(1)->setIsMyTurn(false);
            playerPtr = boardGame.getPlayer(0);
        }
    } // end while (end game)
}


