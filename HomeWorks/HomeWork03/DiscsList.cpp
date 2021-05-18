

#include "DiscsList.h"

DiscsList::DiscsList() : head(NULL), curr(NULL), counter(0){}

DiscsList::~DiscsList() {
    curr = head;
    while(curr)
    {
        head = curr->getNextDisc();
        delete curr;
        counter--;
        curr = head;
    }
}

int DiscsList::sizeList() const {
    return this->counter;
}

void DiscsList::printList() {
    cout.precision(4);
    if(sizeList() == 0) {
        cout << "list is empty" << endl;
    }
    else{
        curr = head;
        while(curr)
        {
            cout << '(' << fixed << curr->getPoint().getX() << ',' << fixed << curr->getPoint().getY() << ") ";
            curr = curr->getNextDisc();
        }
        cout << endl;
    }
}

void DiscsList::addDisc(double x, double y, double vx, double vy, double r) {
    Disc* newDisc = new Disc(x, y, vx, vy, r);
    newDisc->setNextDisc(NULL);
    if(head == NULL)
    {
        head = newDisc;
    }
    else{
        curr = head;
        while(curr->getNextDisc())
        {
            curr = curr->getNextDisc();
        }
        curr->setNextDisc(newDisc);
    }
    this->counter++;
}

Disc* DiscsList::operator[](int index) {
    if(index < sizeList())
    {
        curr = head;
        for(int i = 0; i < index; i++)
        {
            curr = curr->getNextDisc();
        }
        return curr;
    }
    cerr << "Error, index out of range." << endl;
    return NULL;
}


