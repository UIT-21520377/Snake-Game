#include <windows.h>

class Snake
{
private:
    bool isHardMode;
    const int numBlocks = 10;
    int blockX[10], blockY[10];
    int headX, headY;
    int bodyX[100], bodyY[100];
    int lenSnake;
    int dollarX, dollarY;
    int score, highScore;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;
    HANDLE hConsole;
    bool gameOver;
    const int width = 60;
    const int height = 25;

public:
    Snake();
    void HideCursor();
    void ShowCursor();
    void Rules();
    void MainScreen();
    void Draw();
    void Keyboard();
    void Logic();
    void Start();
    void Run();
    void Reset();
    void GenerateBlocks();
};