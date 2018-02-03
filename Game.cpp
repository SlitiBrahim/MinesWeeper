//
// Created by Brahim on 26/01/2018.
//

#include <iostream>
#include "Game.h"

using namespace std;

void Game::askBoardParams(int* params) {

    cout << "== Welcome to MinesWeeper ==" << endl << endl;

    for (int i = 0; i < 2; ++i) {
        do {
            cout << "How many " <<  ((i == 0) ? "rows" : "cols") << ": ";
            cin >> params[i];
        } while (params[i] < 5 || params[i] > 50);
    }

    do {
        cout << "How many mines: ";
        cin >> params[2];
    } while (params[2] < 0 || params[2] >= (params[0] * params[1])); // avoid more mines that boxes

    cout << endl;
}

Game::Game(int rows, int cols, int nbMines) : board(rows, cols, nbMines), isGameOver(false), selectedCoord() {}

bool Game::hasWon() const {

    return false;   // il faut que la propagation fonctionne au complet mais voici le code fonctionnel

    // pour + tard
    int notIndicated = 0;

    for (int i = 0; i < board.getNbRows(); i++) {
        for (int j = 0; j < board.getNbCols(); j++) {
            if (!board.getBoxes()[i][j]->isMineBox() && !board.getBoxes()[i][j]->getIsIndicated()) notIndicated++;

            if (notIndicated >= board.getNbMines()) {
                cout << "\tYOU WIN :)" << endl;
                board.display(true);

                return true;
            }
        }
    }

    return false;
}

bool Game::hasLost() const {

    if (board.getBoxes()[selectedCoord.getY()][selectedCoord.getX()]->isMineBox()) {
        cout << "\tYOU LOOSE" << endl;
        board.display(true);

        return true;
    }

    return false;
}

void Game::askUserToSetCoordinates() {
    int x = 0, y = 0;

    cout << "Indicate the next box without mine" << endl;

    do {
        cout << "Row number [" << board.getRowBounds()[0] << "-" << board.getRowBounds()[1] << "] ? ";
        cin >> y;
    } while (y < board.getRowBounds()[0] || y > board.getRowBounds()[1]);

    do {
        cout << "Column number [" << board.getColBounds()[0] << "-" << board.getColBounds()[1] << "] ? ";
        cin >> x;
    } while (x < board.getColBounds()[0] || x > board.getColBounds()[1]);

    selectedCoord.setY(y);
    selectedCoord.setX(x);

    board.getBoxes()[selectedCoord.getY()][selectedCoord.getX()]->setIsTouched(true);
}

void Game::play() {

    board.generate();
    board.display(true);  //change to false -> now is just for debug
    int neighbors = 0;

    do {
        askUserToSetCoordinates();

        // Empty box Selected
        if (!board.getBoxes()[selectedCoord.getY()][selectedCoord.getX()]->isMineBox()) {
            neighbors = board.getNbNeighbors(selectedCoord);
            if (neighbors == 0) {
                board.getBoxes()[selectedCoord.getY()][selectedCoord.getX()]->setIsIndicated(true);

                board.propagation(selectedCoord);
            }
            else {
                board.getBoxes()[selectedCoord.getY()][selectedCoord.getX()]->setNeighbors(neighbors);
            }
        }

        board.display(false);

        isGameOver = hasLost() || hasWon();
    } while (!(isGameOver));


    cout << "== Thanks for playing this game ==" << endl;
}