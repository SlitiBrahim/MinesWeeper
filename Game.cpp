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

Game::Game(int rows, int cols, int nbMines) : board(rows, cols, nbMines), isGameOver(false), selectedCoord() {}

bool Game::hasWon() const {

    return false;

    // pour + tard
//    int notIndicated = 0;
//
//    for (int i = 0; i < board.getNbRows(); i++) {
//        for (int j = 0; j < board.getNbCols(); j++) {
//            if (notIndicated >= board.getNbMines()) {
//                return true;
//            }
//            // if board.getBoxes[i][j] is type of EmptyBox => notIndicated++
//        }
//    }
//
//    return false;
}

bool Game::hasLost() const {

    if (board.getBoxes()[selectedCoord.getX()][selectedCoord.getY()]->isMineBox()) {
        cout << "YOU LOOSE" << endl;
        board.display();

        return true;
    }

    return false;
}

void Game::askUserToSetCoordinates() {
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

    selectedCoord.setX(x);
    selectedCoord.setY(y);
}

void Game::play() {

    board.display();

    // pour Test; à enlever par la suite
    cout << "Avant Generation" << endl << endl;
    board.generate();
    board.display();


    do {
        askUserToSetCoordinates();

        board.display();

        isGameOver = hasLost() || hasWon();
    } while (!(isGameOver));


    cout << "Thanks for playing this game" << endl;
}