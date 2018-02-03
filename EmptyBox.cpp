//
// Created by Brahim on 26/01/2018.
//

#include <string>
#include <iostream>
#include "EmptyBox.h"
#include "Box.h"

using namespace std;

EmptyBox::EmptyBox() : Box(), isIndicated(false), isTouched(false), neighbors(0) {}

std::string EmptyBox::getRepresentation(int neighbors) const {

    if (isTouched) {
        return (neighbors >= 1) ? to_string(neighbors) : "-";
    }
    else {
        return " ";
    }

}

bool EmptyBox::isMineBox() const {
    return false;
}

bool EmptyBox::getIsIndicated() const {
    return isIndicated;
}

void EmptyBox::setIsIndicated(bool a) {
    isIndicated = a;
}

bool EmptyBox::getIsTouched() const {
    return isTouched;
}

void EmptyBox::setIsTouched(bool a) {
    isTouched = a;
}

int EmptyBox::getNeighbors() const {
    return neighbors;
}

void EmptyBox::setNeighbors(int neighbors) {
    this->neighbors = neighbors;
}

