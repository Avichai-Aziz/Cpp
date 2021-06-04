

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

    // checking collision of disc with disc and disc with wall and update the velocity
    for(int i = 0; i < discsList.sizeList(); i++)
    {
        prevPoint = discsList[i]->getPoint();
        discsList[i]->updateDiscLocation(getDeltaTime());

        // checking collision of disc with disc
        for(int k = 0; k < discsList.sizeList(); k++)
        {
            if(discsList[i]->isDiscsClash(*(discsList[k])) && (i != k))
            {
                // update the disc1 and disc2 velocity and location
                discsList[i]->updateDiscVelocityClashOtherDisc(*(discsList[k]));
                discsList[i]->setIsClashed(true);

                discsList[k]->setIsClashed(true);
                clashed = true;
            }
        }
        // checking collision of disc with wall
        for(int j = 0; j < wallList.sizeList(); j++)
        {
            if(discsList[i]->isDiscClashWall(*(wallList[j])))
            {
                // update the velocity and location of this disc
                discsList[i]->updateDiscVelocityClashWall(*(wallList[j]));
                discsList[i]->setIsClashed(true);
                clashed = true;
            }
        }
        // if clashed then set the location of the disc to the prev location
        if(clashed)
        {
            discsList[i]->setPoint(prevPoint);
            clashed = false;
        }
    }

    // initialize new list of discs
    initNewList();
}

void Table::initNewList() {
    // initialize new list of discs
    DiscsList newDiscList;
    for(int i = 0; i < discsList.sizeList(); i++)
    {
        Disc* tempDisc = new Disc(discsList[i]);
        if(!(tempDisc->getIsClashed()))
        {
            newDiscList.addDisc(tempDisc);
        }
        else if(tempDisc->getType() == "Disc")
        {
            tempDisc->setIsClashed(false);
            newDiscList.addDisc(tempDisc);
        }
        else if(tempDisc->getType() == "Shrinking_Disc")
        {
            tempDisc->setIsClashed(false);
            tempDisc->setRadius((tempDisc->getRadius() * 0.9));
            tempDisc->incCounterClashed();
            if((tempDisc->getCounterClashed() >= 0) && (tempDisc->getCounterClashed() <= 2))
            {
                newDiscList.addDisc(tempDisc);
            }
        }
        else if(tempDisc->getType() == "Exploding_Disc")
        {
            tempDisc->setIsClashed(false);
            tempDisc->incCounterClashed();
            if((tempDisc->getCounterClashed() >= 0) && (tempDisc->getCounterClashed() <= 2))
            {
                double  cTag = 0, rTag = 0, alpha = 0, mTag = 0;

                // algorithm for exploding disc 0, exploding disc 1, exploding disc 2
                cTag = 0.99; // To make sure the new discs are not touching
                rTag = (((sqrt(12)) - 3) * cTag * tempDisc->getRadius());
                alpha = ((4 - ((sqrt(12)))) * tempDisc->getRadius());
                mTag = (tempDisc->getMass() / 3);

                // values of exploding disc 0
                Vector2D tempP0(0, alpha);
                tempP0 += tempDisc->getPoint();
                Vector2D tempV0(0, 1);
                tempV0 += tempDisc->getVelocity();

                // values of exploding disc 1
                Vector2D tempP1((tempDisc->getRadius() - alpha), ((-alpha) / 2) );
                tempP1 += tempDisc->getPoint();
                Vector2D tempV1((sqrt(3) / 2), (-0.5));
                tempV1 += tempDisc->getVelocity();

                // values of exploding disc 2
                Vector2D tempP2((-(tempDisc->getRadius() - alpha)), ((-alpha) / 2) );
                tempP2 += tempDisc->getPoint();
                Vector2D tempV2((-(sqrt(3) / 2)), (-0.5));
                tempV2 += tempDisc->getVelocity();

                // init three new exploding discs, setting the number of clashed of each and add them to the list
                ExplodingDisc* explodingDisc0 = new ExplodingDisc(tempP0.getX(), tempP0.getY(), tempV0.getX(), tempV0.getY(), rTag);
                explodingDisc0->setMass(mTag);
                explodingDisc0->setCounterClashed(tempDisc->getCounterClashed());
                newDiscList.addDisc(explodingDisc0);

                ExplodingDisc* explodingDisc1 = new ExplodingDisc(tempP1.getX(), tempP1.getY(), tempV1.getX(), tempV1.getY(), rTag);
                explodingDisc1->setMass(mTag);
                explodingDisc1->setCounterClashed(tempDisc->getCounterClashed());
                newDiscList.addDisc(explodingDisc1);

                ExplodingDisc* explodingDisc2 = new ExplodingDisc(tempP2.getX(), tempP2.getY(), tempV2.getX(), tempV2.getY(), rTag);
                explodingDisc2->setMass(mTag);
                explodingDisc2->setCounterClashed(tempDisc->getCounterClashed());
                newDiscList.addDisc(explodingDisc2);
            }
        }
    }

    discsList.deleteDiscList();
    discsList = newDiscList; // update the new list to be the current list
    DiscsList tempList;
    newDiscList = tempList;
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