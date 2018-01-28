//
// Created by Brahim on 26/01/2018.
//

#include <iostream>
#include "Game.h"

using namespace std;

void Game::askBoardParams(int* params) {

    cout << "Welcome to MinesWeeper" << endl << endl;

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

Game::Game(int rows, int cols, int nbMines) : board(rows, cols, nbMines), isGameOver(false) {}

bool Game::checkGameOver() {

    int notIndicated = 0;

    for (int i = 0; i < board.getNbRows(); i++) {
        for (int j = 0; j < board.getNbCols(); j++) {
            if (notIndicated >= board.getNbMines()) {
                return true;
            }
            // if board.getBoxes[i][j] is type of EmptyBox => notIndicated++
        }
    }

    return false;
}

void Game::askCoordinates(int* coord) const {
    int x = 0, y = 0;

    cout << "Indicate the next box without mine" << endl;

    do {
        cout << "Row number [" << board.getRowBounds()[0] << "-" << board.getRowBounds()[1] << "] ? ";
        cin >> x;
    } while (x < board.getRowBounds()[0] || x > board.getRowBounds()[1]);

    do {
        cout << "Column number [" << board.getColBounds()[0] << "-" << board.getColBounds()[1] << "] ? ";
        cin >> y;
    } while (y < board.getColBounds()[0] || y > board.getColBounds()[1]);

    coord[0] = x, coord[1] = y;
}

void Game::play() {
    board.display();

    // cout << "Avant Generation" << endl << endl;

    board.generate();

    board.display();

    int coord[2] = {0};
    askCoordinates(coord);

    if (board.getBoxes()[coord[0]][coord[1]]->isMineBox()) {
        cout << "YOU LOOSE" << endl;
        board.display();
        isGameOver = true;
    }

//    while (!isGameOver) {
//        cout << "hello" << endl;
//    }


}