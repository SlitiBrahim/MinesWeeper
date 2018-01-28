//
// Created by Brahim on 26/01/2018.
//

#include <iostream>
#include "MineBox.h"

using namespace std;

MineBox::MineBox() : Box() {}

bool MineBox::isMineBox() const {
    return true;
}

std::string MineBox::getRepresentation() const {
    return "X";
}