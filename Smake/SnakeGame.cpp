#include <ctime>
#include <windows.h>
class SnakeGame
{
private:
    bool gameOver;
    const int width = 60;
    const int height = 25;
    int headX, headY, fruitX, fruitY, score, highScore;
    int bodyX[100], bodyY[100];
    int lenSnake;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;
    HANDLE hConsole;
    bool isHardMode;
    const int numBlocks = 10;
    int blockX[10], blockY[10];

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
    void GenerateBlocks();
};

/*
SnakeGame::SnakeGame()
{
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    highScore = 0;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HideCursor();
}
*/
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
