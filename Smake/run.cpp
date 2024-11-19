#include <conio.h>
#include "Header.h"

void Snake::Run() {
    MainScreen();
    char choice = _getch();

    isHardMode = choice == '2';

    while (!gameOver) {
        Draw();
        Keyboard();
        Logic();
        Sleep(isHardMode ? 50 : 100);
    }

    cout << "Game Over! Score: " << score << endl;
}
Snake::Snake() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(static_cast<unsigned>(time(0)));
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height / 2;
    dollarX = rand() % width;
    dollarY = rand() % height;
    score = 0;
    highScore = 0;
    lenSnake = 0;
    isHardMode = false;
    HideCursor();
}
