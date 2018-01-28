#include <iostream>
#include "Game.h"
#include "Board.h"
#include "EmptyBox.h"
#include "MineBox.h"
#include "Box.h"

#include <vector>

using namespace std;

int main() {

//    vector<Box*> boxes;
//    boxes.push_back(new EmptyBox);
//    boxes.push_back(new MineBox);

    int params[3] = {5, 5, 24};

    // Game::askBoardParams(params);

    Game game(params[0], params[1], params[2]);

    game.play();

    return 0;
}