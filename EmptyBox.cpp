//
// Created by Brahim on 26/01/2018.
//

#include <string>
#include <iostream>
#include "EmptyBox.h"
#include "Box.h"

using namespace std;

EmptyBox::EmptyBox() : Box(), isIndicated(false), isTouched(false) {}

std::string EmptyBox::getRepresentation() const {
    // pour l'instant

    return "T";
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

