//
// Created by Brahim on 26/01/2018.
//

#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <vector>
#include "Box.h"

class Board {

private:

    int nbRows;
    int nbCols;
    std::vector<int> rowBounds;
    std::vector<int> colBounds;
    int nbMines;
    std::vector<std::vector<Box*>> boxes;   //2d vector of box pointers

public:

    Board(int rows, int cols, int nbMines);
    ~Board();

    int getNbRows() const;
    int getNbCols() const;
    std::vector<int> getRowBounds() const;
    std::vector<int> getColBounds() const;
    int getNbMines() const;
    std::vector<std::vector<Box*>> getBoxes() const;

    void generate();
    void display() const;
};


#endif //MINESWEEPER_BOARD_H
