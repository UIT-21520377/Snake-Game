#include <conio.h>
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

void SnakeGame::Input()
{
    if (_kbhit()) {
        switch (_getch()) {
        case 'a': // Left arrow key
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 'd': // Right arrow key
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'w': // Up arrow key
            if (dir != DOWN)
                dir = UP;
            break;
        case 's': // Down arrow key
            if (dir != UP)
                dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}