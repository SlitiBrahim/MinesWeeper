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
        } while (params[i] <= 5 || params[i] > 50);
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

bool Game::randomBoolean() {

    //srand((int)time(0));
    int randomNb = rand() % 10 + 1; // between 1 and 10

    return randomNb <= 5;
}

void Game::play() {
    board.display();

    cout << "Avant Generation" << endl << endl;

    board.generate();

    board.display();

//    while (!isGameOver) {
//        cout << "hello" << endl;
//    }


}