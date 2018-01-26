//
// Created by Brahim on 26/01/2018.
//

#ifndef MINESWEEPER_MINE_H
#define MINESWEEPER_MINE_H

#include "Box.h"

class MineBox : public Box {

public:

    MineBox();
    void hello() const override;
};


#endif //MINESWEEPER_MINE_H
