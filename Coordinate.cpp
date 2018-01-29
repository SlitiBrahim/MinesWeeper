//
// Created by Brahim on 29/01/2018.
//

#include "Coordinate.h"

Coordinate::Coordinate() : x(0), y(0) {}
Coordinate::Coordinate(int x, int y) : x(x), y(y) {}

int Coordinate::getX() const { return x; }
int Coordinate::getY() const { return y; }

void Coordinate::setX(int x) {
    this->x = x;
}

void Coordinate::setY(int y) {
    this->y = y;
}