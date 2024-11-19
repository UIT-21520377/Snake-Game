#include <iostream>
#include "Header.h"

using namespace std;

void Snake::Rules()
{
    system("cls");

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
    cout << "SIMPLE MODE:" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); 
    cout << " - The speed of the snake is slow." << endl;
    cout << " - There are no obstacles." << endl;
    cout << " - You can move through the boundaries (no collisions)." << endl;

    cout << endl; 

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
    cout << "HARD MODE:" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); 
    cout << " - The speed of the snake is much faster." << endl;
    cout << " - There are obstacles you must avoid." << endl;
    cout << " - You cannot touch the boundaries (collisions end the game)." << endl;

    cout << endl; 
}

void Snake::MainScreen()
{
    Rules();// Gọi hàm hiển thị quy tắc chơi.
    
    // In ra hình minh họa rắn (một chú rắn vẽ ASCII).
   cout << "              /^\\               \n";
   cout << "             /   \\              \n";
   cout << "        ____/_____\\____         \n";
   cout << "       /              \\         \n";
   cout << "      /  \\   O   O   / \\        \n";
   cout << "     |    \\    ^    /   |       \n";
   cout << "      \\    \\_______/   /        \n";
   cout << "       \\                /        \n";
   cout << "        \\___/~~~~~\\___/         \n";
   cout << "          /           \\          \n";
   cout << "         /             \\         \n";
   cout << "     ___/               \\___     \n";
   cout << "    /                       \\    \n";
   cout << "   /                         \\   \n";
   cout << "  /                           \\  \n";
   cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    
    // Hiển thị menu chính với các tùy chọn chơi.
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); 
    cout << "  ================================" << endl;
    cout << "  ||        Snake Game         ||" << endl;
    cout << "  ================================" << endl;
    cout << "  ||                           ||" << endl;
    cout << "  ||       Press '1' for       ||" << endl;
    cout << "  ||        ";
    
    // Thay đổi màu chữ để nổi bật "SIMPLE MODE".
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "SIMPLE MODE";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "        ||" << endl;
    cout << "  ||                           ||" << endl;
    cout << "  ================================" << endl;
    cout << "  ||                           ||" << endl;
    cout << "  ||       Press '2' for       ||" << endl;
    cout << "  ||        ";
     // Thay đổi màu chữ để nổi bật "HARD MODE"
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "HARD MODE";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "          ||" << endl;
    cout << "  ||                           ||" << endl;
    cout << "  ================================" << endl;
}

void Snake::Draw()
{
    COORD pos = { 0, 0 };// Vị trí bắt đầu hiển thị ở góc trên trái.
    SetConsoleCursorPosition(hConsole, pos);// Đặt lại con trỏ về vị trí ban đầu.
    // Vẽ đường viền trên cùng.
    for (int i = 0; i < width + 2; i++) {
        if (isHardMode) SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        else SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\xB2";// Ký tự đường viền.
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
            else if (i == dollarY && j == dollarX) {
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
