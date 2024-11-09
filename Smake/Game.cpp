#include "SnakeGame.h"
#include <conio.h>
#include <windows.h>

void SnakeGame::StartGame()
{
    DrawStartScreen();
    char startKey = _getch();
    if (startKey == 's') {
        gameOver = false;
        ResetGame();
    }
    else
        gameOver = true;
}

void SnakeGame::ResetGame()
{
    score = 0;
    x = width / 2;
    y = height / 2;
    nTail = 0;
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void SnakeGame::RunGame()
{
    while (true)
    {
        StartGame();
        while (!gameOver)
        {
            Draw();
            Input();
            Logic();
            Sleep(100);
        }
        _getch();
    }
    ShowCursor();
}