#include <conio.h>
#include <windows.h>
#include "iostream"
#include "stdio.h"
#include "Header.h"

void SnakeGame::StartGame() {
    DrawStartScreen();
    char startKey = _getch();
    if (startKey == '1') {
        isHardMode = false;
        gameOver = false;
        ResetGame();
    }
    else if (startKey == '2') {
        isHardMode = true;
        GenerateBlocks();
        gameOver = false;
        ResetGame();
    }
    else {
        gameOver = true;
    }
}


/*
* void SnakeGame::ResetGame()
{
    score = 0;
    x = width / 2;
    y = height / 2;
    nTail = 0;
    fruitX = rand() % width;
    fruitY = rand() % height;
}
*/
void SnakeGame::ResetGame() {
    score = 0;
    headX = width / 2;
    headY = height / 2;
    lenSnake = 0;

    do {
        fruitX = rand() % width;
        fruitY = rand() % height;

        // Ensure fruit doesn't overlap with any block
        bool overlap = false;
        for (int i = 0; i < numBlocks; i++) {
            if (fruitX == blockX[i] && fruitY == blockY[i]) {
                overlap = true;
                break;
            }
        }
        if (!overlap) break;

    } while (true);
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
            Sleep(isHardMode ? 25 : 100);
        }
        Draw(); 
        _getch();
    }
    ShowCursor();
}