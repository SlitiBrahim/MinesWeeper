//
// Created by Brahim on 26/01/2018.
//

#include <string>
#include <iostream>
#include "EmptyBox.h"
#include "Box.h"

using namespace std;

EmptyBox::EmptyBox() : Box(), isIndicated(false) {}

std::string EmptyBox::getRepresentation() const {
    // pour l'instant

    return " ";
}

bool EmptyBox::getIsIndicated() const {
    return isIndicated;
}