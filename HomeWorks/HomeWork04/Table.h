
#ifndef HW4_CONTINUEDHW3_TABLE_H
#define HW4_CONTINUEDHW3_TABLE_H

#include "DiscsList.h"
#include "WallList.h"
#include "ShrinkingDisc.h"
#include "ExplodingDisc.h"
#include <typeinfo>


// A class of Table, have: simulation time, delta time, list of discs and list of walls
class Table {
private:
    double      simulationTime;
    double      deltaT;
    DiscsList&  discsList;
    WallList&   wallList;

public:
    // constructor
    Table(double simulationTime, double deltaT, DiscsList& discsList, WallList& wallList);

    // getters:

    // return the simulation time
    double  getSimulationTime() const;
    // return the Delta time
    double  getDeltaTime() const;
    // update all discs with locations and velocity, and check collision between discs and wall
    void    updateAllDiscs();
    // initialize new list with discs
    void    initNewList();
    // printing the simulation example : <t>: (<x1>,<y1>)/<r1> (<x2>,<y2>)/<r2>
    void    printSimulation(double time) const;
    // run the simulation
    void    simulation();

};

#endif //HW4_CONTINUEDHW3_TABLE_H
