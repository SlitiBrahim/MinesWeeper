#include <iostream>
#include "Game.h"
#include "Board.h"
#include "EmptyBox.h"
#include "MineBox.h"
#include "Box.h"

#include <vector>

using namespace std;

int main() {

    int params[3] = {9, 9, 14};

    // Game::askBoardParams(params);

    Game game(params[0], params[1], params[2]);

    game.play();

    return 0;
}