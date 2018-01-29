//
// Created by Brahim on 29/01/2018.
//

#ifndef MINESWEEPER_COORDINATE_H
#define MINESWEEPER_COORDINATE_H


class Coordinate {

private:

    int x;
    int y;

public:

    Coordinate();
    Coordinate(int x, int y);

    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);
};


#endif //MINESWEEPER_COORDINATE_H
