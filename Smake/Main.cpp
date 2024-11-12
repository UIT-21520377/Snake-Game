#include "SnakeGame.h"
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    SnakeGame game;
    game.RunGame();
    return 0;
}
