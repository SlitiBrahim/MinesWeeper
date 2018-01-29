//
// Created by Brahim on 26/01/2018.
//

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#include "Board.h"
#include "Coordinate.h"

class Game {

private:

    Board board;
    bool isGameOver;
    Coordinate selectedCoord;

    void askUserToSetCoordinates();
    bool hasWon() const;
    bool hasLost() const;

public:

    static void askBoardParams(int * arr);
    Game(int rows, int cols, int nbMines);
    void play();
};


#endif //MINESWEEPER_GAME_H
