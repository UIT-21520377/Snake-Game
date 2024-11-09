#include "SnakeGame.h"
#include <iostream>

using namespace std;

void SnakeGame::DrawBackground()
{
    system("cls");

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
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

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    cout << "  ================================" << endl;
    cout << "  ||        Snake Game         ||" << endl;
    cout << "  ================================" << endl;
    cout << "  ||                           ||" << endl;
    cout << "  ||       Press 's' for        ||" << endl;
    cout << "  ||        Easy Mode         ||" << endl;
    cout << "  ||                           ||" << endl;
    cout << "  ================================" << endl;
}

void SnakeGame::Draw()
{
    COORD pos;
    pos.X = 0;
    pos.Y = 0;
    SetConsoleCursorPosition(hConsole, pos);

    for (int i = 0; i < width + 2; i++)
        cout << "\xB2";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "\xB2";
            if ((i == y && j == x))
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "\xDB";
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
            else if (i == fruitY && j == fruitX)
                cout << "0";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                        cout << "\xDB";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "\xB2";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "\xB2";
    cout << endl;

    cout << "Score:" << score << "   High Score:" << highScore << "            " << endl;
    cout << "Press W A S D to move, X to quit" << "          " << endl;
    if (gameOver)
    {
        cout << "Game Over! Press any key to continue." << endl;
    }
}