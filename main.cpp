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
//
//    boxes[0]->hello();
//    boxes[1]->hello();

    int xy[2];
    int nbMines;

    for (int i = 0; i < 2; ++i) {
        do {
            cout << "How many " <<  ((i == 0) ? "rows" : "cols") << ": ";
            cin >> xy[i];
        } while (xy[i] <= 5 || xy[i] > 50);
    }

    do {
        cout << "How many mines: ";
        cin >> nbMines;
    } while (nbMines < 0 || nbMines >= min(xy[0], xy[1]));

    Game game(xy[0], xy[1], nbMines);

    game.play();

    return 0;
}