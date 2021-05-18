#include <iostream>
#include <cstdlib>
#include "DiscsList.h"
#include "WallList.h"
#include "Table.h"

//--------------------------------------------------------------------------------------------------
//                  			       Coding
//                  			       ------
//
// General : Air hockey table simulation.
//           The program will be based on a physical model of elastic collisions
//           of the discs with other discs and with the walls.
//
// Input   : Standard input / file.
//           Command: "disc"/"wall"/"simulate" (program will not work without "simulate" command).
//           disc values: x point, y point, velocity x, velocity y and radius.
//           wall values: x point1, y point1, x point2, y point2.
//           simulate values: simulation time, delta time.
//
// Process : Run simulation of table with discs and walls.
//
// Output  : (standard output) simulation time: disc1(x point, y point) disc2(x point, y point)...
//                             <t>: (<x1>,<y1>) (<x2>,<y2>).
//--------------------------------------------------------------------------------------------------
// Programmer : Avichai Aziz
// Date       : 13.05.2021
//--------------------------------------------------------------------------------------------------


using namespace std;

// check the command input
void checkCmdInput(const string& cmd){
    if(!((cmd == "disc") || (cmd == "wall") || (cmd == "simulate")))
    {
        cerr << "Error: illegal input." << endl;
        exit(3);
    }
}
// check if there is a collision with an disc that already exists on the board
void checkCollisionDiscToDisc(Disc& tempDisc, DiscsList& discsList){
    for(int i = 0; i < discsList.sizeList(); i++)
    {
        if(discsList[i]->isDiscsClash(tempDisc))
        {
            cerr << "Error: disc to disc collision detected in initial configuration" << endl;
            exit(4);
        }
    }
}
// check if there is a collision with an wall that already exists on the board with disc that wants to be added
void checkCollisionDiscToWall(Disc& tempDisc, WallList& wallList){
    for(int i = 0; i < wallList.sizeList(); i++)
    {
        if(tempDisc.isDiscClashWall(*wallList[i]))
        {
            cerr << "Error: disc to wall collision detected in initial configuration" << endl;
            exit(4);
        }
    }
}
// check if there is a collision with an disc that already exists on the board with wall that wants to be added
void checkCollisionWallToDisc(DiscsList& discsList, Wall& tempWall){
    for(int i = 0; i < discsList.sizeList(); i++)
    {
        if(discsList[i]->isDiscClashWall(tempWall))
        {
            cerr << "Error: disc to wall collision detected in initial configuration" << endl;
            exit(4);
        }
    }
}
// check if cin input is failed, if failed
void checkFailInput(){
    if(cin.fail()){
        cerr << "Error: illegal input." << endl;
        exit(3);
    }
}

int main() {
    bool        simulateOn = false;
    string      cmd; // command
    double      xDisc = 0, yDisc = 0, vxDisc = 0, vyDisc = 0, radiusDisc = 0;
    double      x1Wall = 0, y1Wall = 0, x2Wall = 0, y2Wall = 0;
    double      simulationTime = 0, deltaT = 0; // simulationTime is T, deltaT is Δt
    DiscsList   discsList;
    WallList    wallList;

    while(cin >> cmd) {
        checkCmdInput(cmd);
        if (cmd == "disc")
        {
            cin >> xDisc >> yDisc >> vxDisc >> vyDisc >> radiusDisc;
            checkFailInput();
            Disc tempDisc(xDisc, yDisc, vxDisc, vyDisc, radiusDisc);
            checkCollisionDiscToDisc(tempDisc, discsList);
            checkCollisionDiscToWall(tempDisc, wallList);
            discsList.addDisc(xDisc, yDisc, vxDisc, vyDisc, radiusDisc);
        }
        else if (cmd == "wall")
        {
            cin >> x1Wall >> y1Wall >> x2Wall >> y2Wall;
            checkFailInput();
            Wall tempWall(x1Wall, y1Wall, x2Wall, y2Wall);

            checkCollisionWallToDisc(discsList, tempWall);
            wallList.addWall(x1Wall, y1Wall, x2Wall, y2Wall);
        }
        else if (cmd == "simulate")
        {
            simulateOn = true;
            cin >> simulationTime >> deltaT;
            checkFailInput();
            Table table(simulationTime, deltaT, discsList, wallList);
            table.simulation();
            break;
        }
    }

    // if reach the end of the file without a command "simulate"
    if(!simulateOn)
    {
        cerr << "Error: illegal input." << endl;
        exit(3);
    }

    return 0;
}
