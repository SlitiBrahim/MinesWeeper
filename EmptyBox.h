//
// Created by Brahim on 26/01/2018.
//

#ifndef MINESWEEPER_EMPTYMINE_H
#define MINESWEEPER_EMPTYMINE_H

#include "Box.h"

class EmptyBox : public Box {

public:

    EmptyBox();
    void hello() const override;
    std::string display() const override;
};


#endif //MINESWEEPER_EMPTYMINE_H
