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
    virtual std::string getRepresentation() const = 0; // pure virtual method
};


#endif //MINESWEEPER_BOX_H
