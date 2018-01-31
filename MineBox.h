//
// Created by Brahim on 26/01/2018.
//

#ifndef MINESWEEPER_MINE_H
#define MINESWEEPER_MINE_H

#include <string>
#include "Box.h"

class MineBox : public Box {

private:

    //A touched box is a box selected by user or a box touched by the propagation of an other user selected box
    bool isTouched;

public:

    MineBox();
    std::string getRepresentation() const override;
    bool isMineBox() const override;
    bool getIsTouched() const override;
    void setIsTouched(bool a) override;
};


#endif //MINESWEEPER_MINE_H
