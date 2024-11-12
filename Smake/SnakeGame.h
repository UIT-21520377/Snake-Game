#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <windows.h>

class SnakeGame
{
private:
    bool gameOver;
    const int width = 60;
    const int height = 25;
    int x, y, fruitX, fruitY, score, highScore;
    int tailX[100], tailY[100];
    int nTail;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;
    HANDLE hConsole;

public:
    SnakeGame();
    void HideCursor();
    void ShowCursor();
    void DrawBackground();
    void DrawStartScreen();
    void StartGame();
    void Draw();
    void Input();
    void Logic();
    void RunGame();
    void ResetGame();
};

#endif
