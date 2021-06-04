
#ifndef HW4_CONTINUEDHW3_DISCSLIST_H
#define HW4_CONTINUEDHW3_DISCSLIST_H

#include <iostream>
#include "ShrinkingDisc.h"
#include "ExplodingDisc.h"

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
    void    addDisc(Disc* newDisc);
    // operator that return the wanted disc in the list by index
    Disc* operator[](int index);
    // delete the disc list
    void    deleteDiscList();

};


#endif //HW4_CONTINUEDHW3_DISCSLIST_H
