#include <iostream>
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
using namespace std;

void SnakeGame::DrawBackground()
{
    system("cls");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "    ~ S N A K E  G A M E ~    " << endl;
    cout << "       ---_ ......._-_--." << endl;
    cout << "      (|\\ /      / /| \\  \\" << endl;
    cout << "      /  /     .'  -=-'   `." << endl;
    cout << "     /  /    .'             )" << endl;
    cout << "   _/  /   .'        _.)   /" << endl;
    cout << "  / o   o        _.-' /  .'" << endl;
    cout << "  \\          _.-'    / .'*|" << endl;
    cout << "   \\______.-'//    .'.' \\*|" << endl;
    cout << "    \\|  \\ | //   .'.' _ |*|" << endl;
    cout << "     `   \\|//  .'.'_ _ _|*|" << endl;
    cout << "      .  .// .'.' | _ _ \\*|" << endl;
    cout << "      \\`-|\\_/ /    \\ _ _ \\*\\" << endl;
    cout << "       `/'\\__/      \\ _ _ \\*\\" << endl;
    cout << "      /^|            \\ _ _ \\*" << endl;
    cout << "     '  `             \\ _ _ \\     " << endl;
    cout << "                       \\_" << endl;
    cout << " ..   ..  ..   ..  .. ______  ______                      " << endl;
    cout << " ||   ||  |\\\\  ||  || ------ |/                   " << endl;
    cout << " ||   ||  ||\\\\ ||  ||   ||   |______             " << endl;
    cout << " ||   ||  || \\\\||  ||   ||   ||             " << endl;
    cout << " \\====//  ||  \\||  ||   ||   |\\_____          " << endl;
}

void SnakeGame::DrawStartScreen()
{
    DrawBackground();

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); 


    cout << "  ================================" << endl;
    cout << "  ||        Snake Game         ||" << endl;
    cout << "  ================================" << endl;
    cout << "  ||                           ||" << endl;
    cout << "  ||       Press '1' for       ||" << endl;
    cout << "  ||        Simple Mode        ||" << endl;
    cout << "  ||                           ||" << endl;
    cout << "  ||       Press '2' for       ||" << endl;
    cout << "  ||        Hard Mode          ||" << endl;
    cout << "  ================================" << endl;
}

void SnakeGame::Draw()
{
    COORD pos;
    pos.X = 0;
    pos.Y = 0;
    SetConsoleCursorPosition(hConsole, pos);

    for (int i = 0; i < width + 2; i++) {
        if (isHardMode) SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        else SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\xB2";
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
        {
            if (j == 0) {
                if (isHardMode) SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                else SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "\xB2";
            }
            if ((i == headY && j == headX))
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // White head
                cout << "\xDB";
            }
            else if (i == fruitY && j == fruitX) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "$";
            }
            else
            {
                bool print = false;
                for (int k = 0; k < lenSnake; k++)
                {
                    if (bodyX[k] == j && bodyY[k] == i)
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
                        cout << "\xDB";
                        print = true;
                    }
                }
                
                if (!print && isHardMode) {
                    for (int b = 0; b < numBlocks; b++) {
                        if (blockX[b] == j && blockY[b] == i) {
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); // Red block
                            cout << "X";
                            print = true;
                        }
                    }
                }
         
                if (!print)
                    cout << " ";
            }

            if (j == width - 1) {
                if (isHardMode) SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                else SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "\xB2";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) {
        if(isHardMode) SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        else SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\xB2";
    }
    cout << endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
    cout << "Score:" << score << "   High Score:" << highScore << "            " << endl;
    cout << "Press W A S D to move, X to quit" << "          " << endl;
    if (gameOver)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "Game Over! Press any key to continue." << endl;
    }
}
