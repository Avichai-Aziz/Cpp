

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
        cout << "" << endl;
    }
    else{
        curr = head;
        while(curr)
        {
            cout << '(' << fixed << curr->getPoint().getX() << ',' << fixed << curr->getPoint().getY() << ")"
            << '/' << fixed << curr->getRadius() << " ";
            curr = curr->getNextDisc();
        }
        cout << endl;
    }
}

void DiscsList::addDisc(Disc* newDisc) {
    Disc* otherDisc(newDisc);
    otherDisc->setNextDisc(NULL);
    if(head == NULL)
    {
        head = otherDisc;
    }
    else{
        curr = head;
        while(curr->getNextDisc())
        {
            curr = curr->getNextDisc();
        }
        curr->setNextDisc(otherDisc);
    }
    curr = NULL;
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

void DiscsList::deleteDiscList() {
    this->~DiscsList();
}
