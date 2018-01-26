//
// Created by Brahim on 26/01/2018.
//

#include <iostream>
#include "MineBox.h"

using namespace std;

MineBox::MineBox() : Box() {}

void MineBox::hello() const {
    cout << "Hello from mine box !!!" << endl;
}
