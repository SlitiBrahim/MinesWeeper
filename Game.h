//
// Created by Brahim on 26/01/2018.
//

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#include "Board.h"

class Game {

private:

    Board board;
    bool isGameOver;

    void welcome() const;
    void displayBoard() const;

public:

    Game(int rows, int cols, int nbMines);
    void play();
};


#endif //MINESWEEPER_GAME_H
