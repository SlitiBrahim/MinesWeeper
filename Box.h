//
// Created by Brahim on 26/01/2018.
//

#ifndef MINESWEEPER_BOX_H
#define MINESWEEPER_BOX_H

#include <iostream>

/**
 * Abstract Class due to one pure vitual method at least existing
 */
class Box {

public:

    int neighbors = 0;

    virtual std::string getRepresentation(int neighbors) const = 0; // pure virtual method
    virtual bool isMineBox() const = 0;

    virtual bool getIsTouched() const = 0;
    virtual void setIsTouched(bool a) = 0;

    virtual bool getIsIndicated() const = 0;
    virtual void setIsIndicated(bool a) = 0;

    virtual int getNeighbors() const = 0;
    virtual void setNeighbors(int neighbors) = 0;
};


#endif //MINESWEEPER_BOX_H
