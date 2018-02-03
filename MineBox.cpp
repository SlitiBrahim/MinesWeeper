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

std::string MineBox::getRepresentation(int neighbors) const {
    return "X";
}

bool MineBox::getIsTouched() const {
    return isTouched;
}

void MineBox::setIsTouched(bool a) {
    isTouched = a;
}

void MineBox::setNeighbors(int neighbors) {
    // no code for this class
}

int MineBox::getNeighbors() const {
    // no code for this class
}

bool MineBox::getIsIndicated() const {}

void MineBox::setIsIndicated(bool a) {}