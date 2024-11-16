#include <ctime>
#include "Header.h"

SnakeGame::SnakeGame() {
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    highScore = 0;
    lenSnake = 0;
    isHardMode = false;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HideCursor();
}

void SnakeGame::GenerateBlocks() {
    for (int i = 0; i < numBlocks; i++) {
        blockX[i] = rand() % width;
        blockY[i] = rand() % height;
    }
}
