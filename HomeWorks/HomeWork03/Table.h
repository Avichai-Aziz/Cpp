

#ifndef HW3_TABLE_H
#define HW3_TABLE_H

#include "DiscsList.h"
#include "WallList.h"

// A class of Table, have: simulation time, delta time, list of discs and list of walls
class Table {
private:
    double      simulationTime;
    double      deltaT;
    DiscsList&   discsList;
    WallList&    wallList;

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
    // printing the simulation example : <t>: (<x1>,<y1>) (<x2>,<y2>)
    void    printSimulation(double time) const;
    // run the simulation
    void    simulation();

};


#endif //HW3_TABLE_H
