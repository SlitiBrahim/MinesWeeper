//
// Created by Brahim on 26/01/2018.
//

#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(int rows, int cols, int nbMines) : board(rows, cols, nbMines), isGameOver(false) {}

void Game::welcome() const {
    cout << "Welcome to MinesWeeper" << endl << endl;
}


void Game::play() {

    welcome();
    board.display();
}