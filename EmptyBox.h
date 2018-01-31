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

    EmptyBox();
    std::string getRepresentation() const override;
    bool isMineBox() const override;
    bool getIsIndicated() const;
    void setIsIndicated(bool a);
    bool getIsTouched() const override;
    void setIsTouched(bool a);
};


#endif //MINESWEEPER_EMPTYMINE_H
