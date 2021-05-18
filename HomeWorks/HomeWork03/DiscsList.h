

#ifndef HW3_DISCSLIST_H
#define HW3_DISCSLIST_H

#include <iostream>
#include "Disc.h"

using namespace std;

// A class of linked list that contains walls
class DiscsList {
private:
    Disc*   head;
    Disc*   curr;
    int     counter; // count the number of discs in the list

public:
    // constructor
    DiscsList();
    // destructor
    ~DiscsList();
    // return the size of the list
    int     sizeList() const;
    // print the list
    void    printList();
    // add disc to the list
    void    addDisc(double x, double y, double vx, double vy, double r);
    // operator that return the wanted disc in the list by index
    Disc* operator[](int index);

};


#endif //HW3_DISCSLIST_H
