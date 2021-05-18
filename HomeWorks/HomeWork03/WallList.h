

#ifndef HW3_WALLLIST_H
#define HW3_WALLLIST_H

#include "Wall.h"

// A class of linked list that contains walls
class WallList {
private:
    Wall*   head;
    Wall*   curr;
    int     counter; // count the number of discs in the list

public:
    // constructor
    WallList();
    // destructor
    ~WallList();
    // return the size of the list
    int     sizeList() const;
    // print the list
    void    printList();
    // add disc to the list
    void    addWall(double x1, double y1, double x2, double y2);
    // operator that return the wanted wall in the list by index
    Wall*   operator[](int index);

};


#endif //HW3_WALLLIST_H
