//
// Created by Brahim on 26/01/2018.
//

#include <iostream>
#include "Board.h"
#include "EmptyBox.h"
#include "MineBox.h"
#include <vector>

using namespace std;

Board::Board() : nbRows(8), nbCols(8), bounds{0, nbRows}, boxes(8*8) {}

Board::Board(int rows, int cols, int nbMines) : nbRows(rows), nbCols(cols), nbMines(nbMines), bounds{0, rows}
{
    for (int i = 0; i < nbRows; ++i) {
        boxes.emplace_back();   // call vector<Box*> constructor  without making copy like push_back() would
        for (int j = 0; j < nbCols; ++j) {
            boxes[i].push_back(new EmptyBox);
        }
    }

}

int Board::getNbCols() const {
    return nbCols;
}

int Board::getNbRows() const {
    return nbRows;
}

std::vector<std::vector<Box*>> Board::getBoxes() const {
    return boxes;
}

void Board::display() const {
    for (int i = 0; i < nbRows; i++) {
        for (int j = 0; j < nbCols; j++) {
            cout << "[" << boxes[i][j]->display() << "]";
        }
        cout << endl;
    }
}


// void Board::generate() {

//}