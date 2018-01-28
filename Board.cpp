//
// Created by Brahim on 26/01/2018.
//

#include <iostream>
#include <random>
#include "Board.h"
#include "EmptyBox.h"
#include "MineBox.h"
#include "Game.h"

using namespace std;

Board::Board(int rows, int cols, int nbMines) : nbRows(rows), nbCols(cols), nbMines(nbMines)
{

    rowBounds.push_back(0);
    rowBounds.push_back(rows-1);

    colBounds.push_back(0);
    colBounds.push_back(cols-1);

    // allocating boxes vector
    for (int i = 0; i < nbRows; ++i) {
        boxes.emplace_back();   // call vector<Box*> constructor without making copy like push_back() would
        for (int j = 0; j < nbCols; ++j) {
            boxes[i].push_back(new EmptyBox);
        }
    }

}

Board::~Board() {
    for (int i = 0; i < nbRows; ++i) {
        for (int j = 0; j < nbCols; ++j) {
            delete boxes[i][j];
        }
    }
}

int Board::getNbCols() const {
    return nbCols;
}

int Board::getNbRows() const {
    return nbRows;
}

vector<int> Board::getRowBounds() const {
    return rowBounds;
}

vector<int> Board::getColBounds() const {
    return colBounds;
}

int Board::getNbMines() const {
    return nbMines;
}

std::vector<std::vector<Box*>> Board::getBoxes() const {
    return boxes;
}

void Board::display() const {
    for (int i = 0; i < nbRows; i++) {
        for (int j = 0; j < nbCols; j++) {
            cout << "[" << boxes[i][j]->getRepresentation() << "]";
        }
        cout << endl;
    }
}

//Box* Board::getRandomBox() const {
//    int rdRow = 0, rdCol = 0;
//
//    rdRow = rand() % rowBounds[1] + rowBounds[0];
//    rdCol = rand() % colBounds[1] + colBounds[0];
//
//    return boxes[rdRow][rdCol];
//}

void Board::generate() {

    int rdRow = 0, rdCol = 0;
    Box* randBox = nullptr;

    srand((int)time(0));
    for (int i = 0; i < nbMines; ++i) {
        do {
            // randBox = getRandomBox();

            rdRow = rand() % (rowBounds[1] + 1);
            rdCol = rand() % (colBounds[1] + 1);

        } while (boxes[rdRow][rdCol]->isMineBox());

        delete boxes[rdRow][rdCol];
        boxes[rdRow][rdCol] = new MineBox;

//        delete randBox;
//        randBox = new MineBox;
    }
}