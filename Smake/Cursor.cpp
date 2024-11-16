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
void SnakeGame::HideCursor()
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &info);
}

void SnakeGame::ShowCursor()
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 10;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &info);
}