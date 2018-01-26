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


void Board::generate() {

    int nbMinesTmp = nbMines;
    bool randomBool;

    srand((int)time(0));

    for (int i = 0; i < nbRows; i++) {
        for (int j = 0; j < nbCols; ++j) {
            if (nbMinesTmp > 0) {
                randomBool = Game::randomBoolean();
                if (randomBool) {
                    delete boxes[i][j];
                    boxes[i][j] = new MineBox;
                    nbMinesTmp--;
                }
            }
            else {
                break;
            }
        }
    }

}