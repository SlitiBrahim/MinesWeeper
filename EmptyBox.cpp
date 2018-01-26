//
// Created by Brahim on 26/01/2018.
//

#include <string>
#include <iostream>
#include "EmptyBox.h"
#include "Box.h"

using namespace std;

EmptyBox::EmptyBox() : Box() {}

void EmptyBox::hello() const {
    cout << "Heloooo from emptyBox " << endl;
}

string EmptyBox::display() const {
    // pour l'instant

    return " ";
}