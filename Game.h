//
// Created by Brahim on 26/01/2018.
//

#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#include "Board.h"

class Game {

private:

    Board board;
    bool isGameOver = checkGameOver();

    bool checkGameOver();

public:

    static void askBoardParams(int * arr);
    Game(int rows, int cols, int nbMines);
    static bool randomBoolean();
    void play();
};


#endif //MINESWEEPER_GAME_H
