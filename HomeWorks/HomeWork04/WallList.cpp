

#include "WallList.h"

WallList::WallList() : head(NULL), curr(NULL), counter(0) {}

WallList::~WallList() {
    curr = head;
    while(curr)
    {
        head = curr->getNextWall();
        delete curr;
        counter--;
        curr = head;
    }
}

int WallList::sizeList() const {
    return this->counter;
}

void WallList::addWall(double x1, double y1, double x2, double y2) {
    Wall* newWall = new Wall(x1, y1, x2, y2);
    newWall->setNextWall(NULL);
    if(head == NULL)
    {
        head = newWall;
    }
    else{
        curr = head;
        while(curr->getNextWall())
        {
            curr = curr->getNextWall();
        }
        curr->setNextWall(newWall);
    }
    this->counter++;
}

Wall* WallList::operator[](int index) {
    if(index < sizeList())
    {
        curr = head;
        for(int i = 0; i < index; i++)
        {
            curr = curr->getNextWall();
        }
        return curr;
    }
    std::cerr << "Error, index out of range." << std::endl;
    return NULL;
}

void WallList::printList() {
    if(sizeList() == 0) {
        std::cout << "list is empty" << std::endl;
    }
    else{
        curr = head;
        while(curr)
        {
            std::cout << '(' << curr->getPoint1().getX() << ',' << curr->getPoint1().getY() << ')' <<
                      '(' << curr->getPoint2().getX() << ',' << curr->getPoint2().getY() << ')' << std::endl;
            curr = curr->getNextWall();
        }
    }
}
