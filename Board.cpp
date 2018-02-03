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

/**
 * Désolé pour cet "algorithme" très sale, quelques lacunes en algorithmiquee, et manque de café
 */
int Board::getNbNeighbors(Coordinate coord) const {

    // code
    int result = 0;
    int left = 0, right = 0, top = -1, bottom = 0;
    int rowMin = 0, rowMax = 0, colMin = 0, colMax = 0;
    //left = coord.getX() - 1;    // -1: because only adjacent boxes

    left = coord.getX();
    right = nbCols-1 - coord.getX();  // -1 because indexes start at 0
    top = coord.getY();
    bottom = nbRows-1 - coord.getY();


    //min = ((left > 0) ? coord.getX() - 1 : 1);
    rowMin = coord.getY();
    rowMax = coord.getY();
    colMin = coord.getX();

    // LEFT and RIGHT
    if (left > 0) {
        //au moins une case libre à droite
        if (right >= 1) {
            colMin -= 1;
        } else colMin -= 2;
        colMax = colMin + 2;
    }
    else {
        colMax = colMin + 2;
    }
    for (int l = colMin; l <= colMax; ++l) {
        if (boxes[coord.getY()][l]->isMineBox()) result++;
    }

    // TOP and BOTTOM
    if (top > 0) {

        if (bottom > 0) {
            rowMin -= 1;
            //  calculer ligne du bas
            for (int k = colMin; k <= colMax; ++k) {
                if (boxes[coord.getY()+1][k]->isMineBox()) result++;
            }
        }
        else {
            rowMin -= 2;
        }
    } else {

        rowMin += 1;
        rowMax = rowMin + 2;
    }
    for (int row = rowMin; row < rowMax; row++) {
        for (int col = colMin ; col <= colMax; col++) {
            if (boxes[row][col]->isMineBox()) result++;
        }
    }

    return result;
}

void Board::display(bool verbose) const {
    cout << endl;
    for (int i = 0; i < nbRows; i++) {
        for (int j = 0; j < nbCols; j++) {
            cout << "[";

            if (!verbose) {

                // is an EmptyBox and was touched
                if (!(boxes[i][j]->isMineBox()) && (boxes[i][j]->getIsTouched())) {
                    cout << boxes[i][j]->getRepresentation(boxes[i][j]->getNeighbors());
                }
                else {
                    cout << " ";
                }
            }
            else {
                cout << boxes[i][j]->getRepresentation(0);
            }

            cout << "]";
        }
        cout << endl;
    }
    cout << endl;
}

void Board::generate() {

    int rdRow = 0, rdCol = 0;
    Box** randBox = nullptr;

    srand((int)time(0));
    for (int i = 0; i < nbMines; ++i) {
        do {
            // randBox = getRandomBox();

            rdRow = rand() % (rowBounds[1] + 1);
            rdCol = rand() % (colBounds[1] + 1);

        } while (boxes[rdRow][rdCol]->isMineBox());

        randBox = &boxes[rdRow][rdCol];

        delete *randBox;
        *randBox = new MineBox;
    }
}