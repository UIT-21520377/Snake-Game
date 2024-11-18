#include <ctime>
#include "Header.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Snake game;
    game.Run();
    return 0;
}
