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

protected:

    virtual void hello() const = 0; // pure virtual method

public:
    virtual std::string display() const = 0;   // pure virtual method
};


#endif //MINESWEEPER_BOX_H
