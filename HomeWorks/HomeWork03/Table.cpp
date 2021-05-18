

#include "Table.h"


Table::Table(double simulationTime, double deltaT, DiscsList& discsList, WallList& wallList):
            simulationTime(simulationTime), deltaT(deltaT), discsList(discsList), wallList(wallList){}

double Table::getSimulationTime() const{
    return simulationTime;
}

double Table::getDeltaTime() const {
    return deltaT;
}

void Table::updateAllDiscs() {
    Vector2D    prevPoint;
    bool        clashed = false;

    for(int i = 0; i < discsList.sizeList(); i++)
    {
        prevPoint = discsList[i]->getPoint();
        discsList[i]->updateDiscLocation(getDeltaTime());

        // checking collision of disc with disc or wall
        for(int k = 0; k < discsList.sizeList(); k++)
        {
            if(discsList[i]->isDiscsClash(*(discsList[k])) && (i != k))
            {
                // update the disc1 and disc2 velocity and location
                clashed = true;
                discsList[i]->updateDiscVelocityClashOtherDisc(*(discsList[k]));
            }
        }
        for(int j = 0; j < wallList.sizeList(); j++)
        {
            if(discsList[i]->isDiscClashWall(*(wallList[j])))
            {
                clashed = true;
                // update the velocity and location of this disc
                discsList[i]->updateDiscVelocityClashWall(*(wallList[j]));
            }
        }
        if(clashed)
        {
            discsList[i]->setPoint(prevPoint);
            clashed = false;
        }
    }
}

void Table::printSimulation(double time) const{
    cout << time << ": ";
    discsList.printList();
}

void Table::simulation() {
    for(double time = 0; time <= getSimulationTime(); time+=getDeltaTime())
    {
        printSimulation(time);
        updateAllDiscs();
    }
}











