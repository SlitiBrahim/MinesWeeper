//
// Created by Brahim on 26/01/2018.
//

#ifndef MINESWEEPER_MINE_H
#define MINESWEEPER_MINE_H

#include <string>
#include "Box.h"

class MineBox : public Box {

public:

    MineBox();
    std::string getRepresentation() const override;
    bool isMineBox() const override;
};


#endif //MINESWEEPER_MINE_H
