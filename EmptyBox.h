//
// Created by Brahim on 26/01/2018.
//

#ifndef MINESWEEPER_EMPTYMINE_H
#define MINESWEEPER_EMPTYMINE_H

#include "Box.h"

class EmptyBox : public Box {

private:

    bool isIndicated;
    bool isTouched; //A touched box is a box selected by user or a box touched by the propagation of an other user selected box

public:

    int neighbors;

    EmptyBox();
    std::string getRepresentation(int neighbors) const override;
    bool isMineBox() const override;
    bool getIsIndicated() const override;
    void setIsIndicated(bool a) override;
    bool getIsTouched() const override;
    void setIsTouched(bool a) override;

    int getNeighbors() const override;
    void setNeighbors(int neighbors) override;
};


#endif //MINESWEEPER_EMPTYMINE_H
