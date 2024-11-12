#include "SnakeGame.h"
#include <ctime>

SnakeGame::SnakeGame()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    highScore = 0;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HideCursor();
}
