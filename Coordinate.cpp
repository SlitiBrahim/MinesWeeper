//
// Created by Brahim on 29/01/2018.
//

#include "Coordinate.h"

Coordinate::Coordinate() : y(0), x(0) {}
Coordinate::Coordinate(int y, int x) : y(y), x(x) {}

int Coordinate::getY() const { return y; }
int Coordinate::getX() const { return x; }

void Coordinate::setY(int y) {
    this->y = y;
}

void Coordinate::setX(int x) {
    this->x = x;
}

