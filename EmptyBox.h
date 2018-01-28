//
// Created by Brahim on 26/01/2018.
//

#ifndef MINESWEEPER_EMPTYMINE_H
#define MINESWEEPER_EMPTYMINE_H

#include "Box.h"

class EmptyBox : public Box {

private:

    bool isIndicated;

public:

    EmptyBox();
    std::string getRepresentation() const override;
    bool getIsIndicated() const;
    bool isMineBox() const override;
};


#endif //MINESWEEPER_EMPTYMINE_H
